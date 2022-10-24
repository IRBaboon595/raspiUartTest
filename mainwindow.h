#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>

#define	SYNCHRO                     0x02
#define UART_ADDR                   0x0A
#define SERVICE_BITS_LEN            0x06

#define ECHO						0x00
#define TEXT                        0x01

#define ON                          0x01
#define OFF                         0x00

typedef union{
    uint16_t 	istd;
    uint8_t 	cstd[2];
}std_union;

typedef union{
    uint32_t 	listd;
    uint16_t 	istd[2];
    uint8_t 	cstd[4];
}long_std_union;

typedef union{
    uint64_t 	llistd;
    uint32_t 	listd[2];
    uint16_t 	istd[4];
    uint8_t 	cstd[8];
}long_long_std_union;

enum class Interface : uint8_t
{
    USB = 0,
    UART = 1
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSerialPort                     *COM;
    QSerialPort                     *COM_2;

private:
    Ui::MainWindow *ui;

    char            m_crc = 0;

    uint8_t         m_uartCommand;
    Interface       m_currentInterface;

    QString         *cur_temp;

    uint64_t        time;
    QTimer          *timer_echo;
    QByteArray      ba;
    QByteArray      ba_2;

    //std_union       len;

private slots:
    void getEcho();
    void connectCOM();
    void getEcho_2();
    void connectCOM_2();
    void readData();
    void readData_2();
    void parseData(QByteArray *data, QString comName);
    void on_com_refresh_button_clicked();
    void timer_echo_timeout();

    void on_com_refresh_button_2_clicked();
    void on_sendPushButton_clicked();
    void on_choseSenderSlider_sliderReleased();
};
#endif // MAINWINDOW_H
