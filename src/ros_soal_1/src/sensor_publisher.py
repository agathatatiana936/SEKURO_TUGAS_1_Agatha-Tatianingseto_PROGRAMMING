#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import random

class SensorPublisher(Node):
    def __init__(self):
        super().__init__('sensor_publisher')
        self.publish_rate = 1.0

        # PUBLISHER
        self.publisher = self.create_publisher(
            String,
            'sensor_data',   
            10
        )

        # TIMER
        self.timer = self.create_timer(
            1.0 / self.publish_rate,
            self.timer_callback
        )

        self.counter = 0
        self.get_logger().info('=== Sensor Publisher Node telah aktif! ===')

    def timer_callback(self):
        self.counter += 1

        suhu     = round(random.uniform(25.0, 45.0), 2)
        jarak    = round(random.uniform(10.0, 200.0), 2)
        status   = "NORMAL" if suhu < 40.0 else "WARNING"

        msg = String()
        msg.data = (
            f"[SENSOR #{self.counter}] "
            f"Suhu: {suhu} C | "
            f"Jarak: {jarak} cm | "
            f"Status: {status}"
        )

        self.publisher.publish(msg)
        self.get_logger().info(f'Mengirim -> {msg.data}')


def main(args=None):
    rclpy.init(args=args)
    node = SensorPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()