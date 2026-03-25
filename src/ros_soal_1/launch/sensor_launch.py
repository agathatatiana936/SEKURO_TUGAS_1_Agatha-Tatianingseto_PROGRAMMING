from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([

        Node(
            package='robot_sensor_ws',
            executable='sensor_publisher.py',
            name='sensor_publisher',
            output='screen'
        ),

        Node(
            package='robot_sensor_ws',
            executable='sensor_subscriber.py',
            name='sensor_subscriber',
            output='screen'
        ),

    ])