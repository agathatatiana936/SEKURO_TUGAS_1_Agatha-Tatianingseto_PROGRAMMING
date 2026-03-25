#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class SensorSubscriber(Node):
    def __init__(self):
        super().__init__('sensor_subscriber')

        # SUBSCRIBER
        self.subscriber = self.create_subscription(
            String,
            'sensor_data',
            self.subscriber_callback,
            10 
        )

        self.total_received = 0
        self.warning_count  = 0
        self.get_logger().info('=== Sensor Subscriber Node telah aktif! ===')

    def subscriber_callback(self, msg):
        self.total_received += 1

        if "WARNING" in msg.data:
            self.warning_count += 1
            self.get_logger().warn(
                f'[PERINGATAN] Data diterima: {msg.data}'
            )
        else:
            self.get_logger().info(
                f'[OK] Data diterima: {msg.data}'
            )

        self.get_logger().info(
            f'--- Total diterima: {self.total_received} | '
            f'Warning: {self.warning_count} ---'
        )


def main(args=None):
    rclpy.init(args=args)
    node = SensorSubscriber()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()