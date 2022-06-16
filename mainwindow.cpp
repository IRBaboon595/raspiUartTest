#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer_echo = new QTimer();
    ui->getLineEdit->setText("Pisun");
    COM = new QSerialPort(this);
    COM_2 = new QSerialPort(this);
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
            ui->com_combobox->addItem(info.portName());
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
            ui->com_combobox_2->addItem(info.portName());

    connect(ui->com_button, SIGNAL(clicked(bool)), this, SLOT(connectCOM()));
    connect(ui->com_button_2, SIGNAL(clicked(bool)), this, SLOT(connectCOM_2()));
    connect(ui->echo_button, SIGNAL(clicked(bool)), this, SLOT(getEcho()));
    connect(ui->echo_button_2, SIGNAL(clicked(bool)), this, SLOT(getEcho_2()));
    connect(timer_echo, SIGNAL(timeout()), this, SLOT(timer_echo_timeout()));

    connect(COM, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(COM_2, SIGNAL(readyRead()), this, SLOT(readData_2()));
}

MainWindow::~MainWindow()
{
    COM->close();
    delete ui;
}

/**************************************** Service Functions ****************************************/

void MainWindow::connectCOM()
{
    if(COM->portName() != ui->com_combobox->currentText())
    {
        COM->close();
        COM->setPortName(ui->com_combobox->currentText());
    }

    COM->setBaudRate(QSerialPort::Baud115200, QSerialPort::AllDirections);
    COM->setDataBits(QSerialPort::Data8);
    COM->setParity(QSerialPort::NoParity);
    COM->setStopBits(QSerialPort::OneStop);
    COM->setFlowControl(QSerialPort::NoFlowControl);
    COM->setReadBufferSize(0);
    if(COM->open(QSerialPort::ReadWrite))
    {
        ui->comstate_label->setText("<FONT COLOR=#008000>Opened</FONT>");
        ui->com_button->setText("Close port");
    }
    else
    {
        COM->close();
        ui->comstate_label->setText("<FONT COLOR=red>Closed</FONT>");
        ui->com_button->setText("Open port");
    }
}

void MainWindow::connectCOM_2()
{
    if(COM_2->portName() != ui->com_combobox_2->currentText())
    {
        COM_2->close();
        COM_2->setPortName(ui->com_combobox_2->currentText());
    }

    COM_2->setBaudRate(QSerialPort::Baud115200, QSerialPort::AllDirections);
    COM_2->setDataBits(QSerialPort::Data8);
    COM_2->setParity(QSerialPort::NoParity);
    COM_2->setStopBits(QSerialPort::OneStop);
    COM_2->setFlowControl(QSerialPort::NoFlowControl);
    COM_2->setReadBufferSize(0);
    if(COM_2->open(QSerialPort::ReadWrite))
    {
        ui->comstate_label_2->setText("<FONT COLOR=#008000>Opened</FONT>");
        ui->com_button_2->setText("Close port");
    }
    else
    {
        COM_2->close();
        ui->comstate_label_2->setText("<FONT COLOR=red>Closed</FONT>");
        ui->com_button_2->setText("Open port");
    }
}

/***************************************** Control Functions *********************************************/

void MainWindow::getEcho()
{
    QByteArray ba_1;
    char len = 0x06;
    char crc = 0;
    char echo = ECHO;
    ba_1.append(SYNCHRO);
    ba_1.append(char(0x00));
    ba_1.append(len);
    ba_1.append(UART_ADDR);
    ba_1.append(echo);
    for(int i = 0; i < ba_1.size(); i++)
    {
        crc ^= ba_1.at(i);
    }
    ba_1.append(crc);
    qDebug() << COM->readBufferSize();
    if(COM->write(ba_1) != -1)
    {
        COM->waitForBytesWritten(200);
        COM->waitForReadyRead(100);
    }
}

void MainWindow::getEcho_2()
{
    QByteArray ba_1;
    char len = 0x06;
    char crc = 0;
    char echo = ECHO;
    ba_1.append(SYNCHRO);
    ba_1.append(char(0x00));
    ba_1.append(len);
    ba_1.append(UART_ADDR);
    ba_1.append(echo);
    for(int i = 0; i < ba_1.size(); i++)
    {
        crc ^= ba_1.at(i);
    }
    ba_1.append(crc);
    qDebug() << COM_2->readBufferSize();
    if(COM_2->write(ba_1) != -1)
    {
        COM_2->waitForBytesWritten(200);
        COM_2->waitForReadyRead(100);
    }
}

void MainWindow::timer_echo_timeout()
{
    ui->service_message->setText("Empty");
}

void MainWindow::on_com_refresh_button_clicked()
{
    ui->com_combobox->clear();
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
            ui->com_combobox->addItem(info.portName());
}


void MainWindow::on_com_refresh_button_2_clicked()
{
    ui->com_combobox_2->clear();
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
            ui->com_combobox_2->addItem(info.portName());
}

void MainWindow::readData()
{
    qDebug() << "ReadyRead_Got from COM";
    ba.append(COM->readAll());
    qDebug() << ba.size();
    parseData(&ba, "COM");
}

void MainWindow::readData_2()
{
    qDebug() << "ReadyRead_Got from COM 2";
    ba_2.append(COM_2->readAll());
    qDebug() << ba_2.size();
    parseData(&ba_2, "COM 2");
}

void MainWindow::parseData(QByteArray *data, QString comName)
{
    char temp = 0;
    bool trigger = true;
    int idx = data->indexOf(SYNCHRO, 0);
    QString message;
    std_union len;
    len.istd = 0;

    QString tempString;
    QByteArray tempBa;

    if(idx >= 0)
    {
        qDebug() << "Synchro byte found";
        if(idx > 0)
        {
            data->remove(0,idx);
            idx = 0;
        }
        while((data->size() >= 6) && (trigger))
        {
            qDebug() << "Potential parcel len achieved";
            len.cstd[1] = uint8_t(data->at(1));
            len.cstd[0] = uint8_t(data->at(2));
            qDebug() << len.istd;
            temp = data->at(3);
            if(temp == UART_ADDR)
            {
                qDebug() << "Address achieved";
                for(int i = 0; i < len.istd; i++)
                {
                    CRC ^= data->at(i);
                }
                if(CRC == 0)
                {
                    qDebug() << "XOR approved";
                    temp = data->at(4);
                    switch (temp)
                    {
                    case ECHO:
                        if(comName == "COM")
                        {
                            ui->service_message->setText("Echo Got");
                        }
                        else if(comName == "COM 2")
                        {
                            ui->service_message_2->setText("Echo Got");
                        }
                        else
                        {
                            data->clear();
                            return;
                        }

                        timer_echo->start(1000);
                        uart_command = 0;
                        break;
                    case TEXT:
                        data->remove(0, 5);
                        data->truncate(len.istd - 6);
                        message.append(data->constData());
                        ui->getLineEdit->setText(message);
                        uart_command = 1;
                        break;
                    default:

                        uart_command = 255;
                        break;
                    }
                    trigger = false;
                    data->clear();
                }
                else
                {
                    qDebug() << "XOR error";
                    idx = data->indexOf(SYNCHRO, 1);
                    int bad_len = idx;
                    data->remove(0, bad_len);
                }

            }
            else
            {
                qDebug() << "Address error";
                idx = data->indexOf(SYNCHRO, 1);
                int bad_len = idx;
                data->remove(0, bad_len);
            }
        }
    }
    else
    {
        qDebug() << "No Synchro";
        data->clear();
    }
    CRC = 0;
}

void MainWindow::on_sendPushButton_clicked()
{
    QByteArray ba_1;
    char crc = 0;

    ba_1.append(SYNCHRO);
    ba_1.append(char(0x00));
    ba_1.append(6 + ui->sendLineEdit->text().size());
    ba_1.append(UART_ADDR);
    ba_1.append(TEXT);
    ba_1.append(ui->sendLineEdit->text().toUtf8());
    for(int i = 0; i < ba_1.size(); i++)
    {
        crc ^= ba_1.at(i);
    }
    ba_1.append(crc);
    qDebug() << COM->readBufferSize();
    if(COM->write(ba_1) != -1)
    {
        COM->waitForBytesWritten(200);
        COM->waitForReadyRead(100);
    }
}

