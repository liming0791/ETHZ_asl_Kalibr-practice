# Android

1. Use Android IMU-Camera recorder to record IMU-Camera data.
2. Use **bin2image** convert .bin data to .png images.
3. Use **Kalibr_bagcreator** to create rosbag file. (note: some issue with absolute path and the last dot)
4. Use **calibrator** to calibrate.

# Rokid-ic-Cube (A custom device with camera and imu)

1. Use **Adafruit_IMU_ROS** to publish imu topic.
2. Use **uvc_camera** (or other packages) to publish usb camera image.
3. Use **image_proc** to convert rgb image to grayscale image. (must do)
4. Use **rosbag** to record data.
5. Use **calibrator** to calibrate.


PS: Well, it's really complex and annoying :( . But it's necessary.
