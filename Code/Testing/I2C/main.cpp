#include <QCoreApplication>
#include <wiringPiI2C.h>
#include <QDebug>
#include <QThread>
#include <QList>
#include "mpu6050.h"
#include "pca9685.h"
#include "esc.h"

int file_i2c;
int length;
unsigned char buffer[60] = {0};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug()<<"Hello World!";
    qDebug()<<"I2C Testing";

    MPU6050 *mpu = new MPU6050();
    PCA9685 *pwm = new PCA9685();
    ESC *esc = new ESC(15);

    //pwm->setAllPwm(0, 4000);
    QThread::sleep(1.0);

    QList<double> xList, yList;
    /*while(true)
    {
        mpu->read();
        xList<<mpu->xRot;
        if(xList.length() > 20)
        {
            xList.removeFirst();
        }

        yList<<mpu->yRot;
        if(yList.length() > 20)
        {
            yList.removeFirst();
        }

        double xAvg = 0.0;
        for(int i = xList.indexOf(xList.first()); i < xList.indexOf(xList.last()); i++)
        {
            xAvg += xList.at(i);
        }

        double yAvg = 0.0;
        for(int i = yList.indexOf(yList.first()); i < yList.indexOf(yList.last()); i++)
        {
            yAvg += yList.at(i);
        }

        xAvg /= (double)xList.length();
        yAvg /= (double)yList.length();

        if(xAvg < 0)
        {
            xAvg = -xAvg;
        }
        if(yAvg < 0)
        {
            yAvg = -yAvg;
        }

        pwm->setPwm(0, 0, ((xAvg / 90.0) * 4095));
        //qDebug()<<"x:"<<((xAvg / 90.0));
        pwm->setPwm(1, 0, ((yAvg / 90.0) * 4095));
        //qDebug()<<"y: "<<((yAvg / 90.0));
    }*/

    /*while(true)
    {
        QTextStream s(stdin);
        QString value = s.readLine();
        double intValue = value.toDouble();
        pwm->setPwm(15, 0, intValue);
    }*/

    while(true)
    {
        QTextStream s(stdin);
        int value = s.readLine().toInt();
        esc->setPower(value);
    }

    /*pwm->setPwm(15, 0, 0);
    QThread::sleep(1);
    pwm->setPwm(15, 0, 200);
    QThread::sleep(1);
    pwm->setPwm(15, 0, 0);
    QThread::sleep(1);
    pwm->setPwm(15, 0, 300);*/

    return a.exec();
}
