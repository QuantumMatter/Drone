#include <QCoreApplication>
#include <unistd.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <wiringPiI2c.h>

int file_i2c;
int length;
unsigned char buffer[60] = {0};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
