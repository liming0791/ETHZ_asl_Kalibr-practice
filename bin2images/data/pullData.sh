 adb pull /sdcard/imu_data/imu.csv ./dataset/
 adb pull /sdcard/camera_images/images.bin ./
 cd dataset/cam/
 rm *.png
 ../../../bin/example ../../images.bin
