#ifndef MPU6050_H
#define MPU6050_H

#include <QObject>
#include <QDebug>
#include <wiringPiI2C.h>

//Device Setup
#define address         0x68
#define power_mgmt_1    0x6b
#define power_mgmt_2    0x6c
//Gyro Data
#define gyro_x_out      0x43
#define gyro_y_out      0x45
#define gyro_z_out      0x47
//Accelerometer Data
#define accel_x_out     0x3b
#define accel_y_out     0x3d
#define accel_z_out     0x3f

class MPU6050 : public QObject
{
    Q_OBJECT
public:
    explicit MPU6050(QObject *parent = 0);

    double gyrox, gyroxScaled;
    double gyroy, gyroyScaled;
    double gyroz, gyrozScaled;

    double accelx, accelxScaled;
    double accely, accelyScaled;
    double accelz, accelzScaled;

    double xRot, yRot;

private:
    int fd;
    double readWord(int reg);
    double readWord2C(int reg);
    double getYRotation(double x, double y, double z);
    double getXRotation(double x, double y, double z);
    double distance(double a, double b);

signals:

public slots:
    void read();
};

#endif // MPU6050_H
