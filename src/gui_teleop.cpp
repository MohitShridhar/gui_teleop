#include <stdio.h>
#include <sstream>

#include <QPainter>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTimer>
#include <QCheckBox>

#include <geometry_msgs/Twist.h>

#include "drive_widget.h"
#include "gui_teleop.h"

namespace sesto_rviz_plugins
{

  GuiTeleop::GuiTeleop( QWidget* parent )
    : rviz::Panel( parent )
    , linear_velocity_( 0 )
    , angular_velocity_( 0 )
  {

    // max_linear_vel = DEFAULT_MAX_LINEAR_VEL;
    // max_angular_vel = DEFAULT_MAX_ANGULAR_VEL;

    QHBoxLayout* topic_layout = new QHBoxLayout;

    topic_layout->addWidget( new QLabel( "Output Topic:" ));
    output_topic_editor_ = new QLineEdit;
    topic_layout->addWidget( output_topic_editor_ );

    QHBoxLayout* max_vel_layout = new QHBoxLayout;

    max_vel_layout->addWidget(new QLabel("Max Lin"));
    max_linear_vel_editor_ = new QLineEdit;
    max_vel_layout->addWidget(max_linear_vel_editor_);

    max_vel_layout->addWidget(new QLabel("Max Ang"));
    max_angular_vel_editor_ = new QLineEdit;
    max_vel_layout->addWidget(max_angular_vel_editor_);

    QHBoxLayout* pub_checkbox_layout = new QHBoxLayout;

    pub_check_box_ = new QCheckBox("Publish", this);
    pub_checkbox_layout->addWidget(pub_check_box_);

    drive_widget_ = new DriveWidget;

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addLayout( topic_layout );
    layout->addLayout( max_vel_layout);
    layout->addLayout( pub_checkbox_layout);
    layout->addWidget( drive_widget_ );
    setLayout( layout );

    QTimer* output_timer = new QTimer( this );

    connect( drive_widget_, SIGNAL( outputVelocity( float, float )), this, SLOT( setVel( float, float )));
    connect( output_topic_editor_, SIGNAL( editingFinished() ), this, SLOT( updateTopic() ));
    connect( output_timer, SIGNAL( timeout() ), this, SLOT( sendVel() ));
    connect( max_linear_vel_editor_, SIGNAL(editingFinished()), this, SLOT( setMaxLinearVel() ));
    connect( max_angular_vel_editor_, SIGNAL(editingFinished()), this, SLOT( setMaxAngularVel() ));

    output_timer->start( 100 );

    drive_widget_->setEnabled( false );
  }

  void GuiTeleop::setVel( float lin, float ang )
  {
    linear_velocity_ = lin;
    angular_velocity_ = ang;
  }

  void GuiTeleop::updateTopic()
  {
    setTopic( output_topic_editor_->text() );
  }

  void GuiTeleop::setMaxLinearVel()
  {
    max_linear_vel = max_linear_vel_editor_->text().toFloat();
  }

  void GuiTeleop::setMaxAngularVel()
  {
    max_angular_vel = max_angular_vel_editor_->text().toFloat();
  }

  void GuiTeleop::setTopic( const QString& new_topic )
  {
    if( new_topic != output_topic_ )
    {
      output_topic_ = new_topic;

      if( output_topic_ == "" )
      {
        velocity_publisher_.shutdown();
      }
      else
      {
        velocity_publisher_ = nh_.advertise<geometry_msgs::Twist>( output_topic_.toStdString(), 1 );
      }

      Q_EMIT configChanged();
    }

    drive_widget_->setEnabled( output_topic_ != "" );
  }

  void GuiTeleop::sendVel()
  {
    if( ros::ok() && velocity_publisher_ && pub_check_box_->isChecked())
    {
      suppressSpeed();

      geometry_msgs::Twist msg;
      msg.linear.x = linear_velocity_;
      msg.linear.y = 0;
      msg.linear.z = 0;
      msg.angular.x = 0;
      msg.angular.y = 0;
      msg.angular.z = angular_velocity_;
      velocity_publisher_.publish( msg );
    }
  }

  void GuiTeleop::suppressSpeed()
  {
    if (linear_velocity_ > max_linear_vel) {
      linear_velocity_ = max_linear_vel;
    }

    if (angular_velocity_ > max_angular_vel) {
      angular_velocity_ = max_angular_vel;
    }

  }

// TODO: save other states
  void GuiTeleop::save( rviz::Config config ) const
  {
    rviz::Panel::save( config );
    config.mapSetValue( "Topic", output_topic_ );
    config.mapSetValue("MaxLinVel", max_linear_vel);
    config.mapSetValue("MaxAngVel", max_angular_vel);
  }

  void GuiTeleop::load( const rviz::Config& config )
  {
    rviz::Panel::load( config );
    QString topic;
    if( config.mapGetString( "Topic", &topic ))
    {
      output_topic_editor_->setText( topic );
      updateTopic();
    }

    QString initMaxLinVel, initMaxAngVel;

    if (config.mapGetString("MaxLinVel", &initMaxLinVel)) {
      max_linear_vel = initMaxLinVel.toFloat();
    } else {
      max_linear_vel = DEFAULT_MAX_LINEAR_VEL;
    }

    std::ostringstream temp;
    temp << max_linear_vel;

    max_linear_vel_editor_->setText(QString::fromStdString(temp.str().c_str()));

    if (config.mapGetString("MaxAng", &initMaxAngVel)) {
      max_angular_vel = initMaxAngVel.toFloat();  
    } else {
      max_angular_vel = DEFAULT_MAX_ANGULAR_VEL;
    }

    temp << max_linear_vel;

    max_angular_vel_editor_->setText(QString::fromStdString(temp.str().c_str()));

  } 

} 

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(sesto_rviz_plugins::GuiTeleop,rviz::Panel )
