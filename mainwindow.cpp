#include "mainwindow.h"

#include "ui_mainwindow.h"

#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QStringList>
#include <QAbstractSocket>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , tcp_socket(new QTcpSocket(this))
{
    ui->setupUi(this);
    setWindowTitle("Command Parser Client");
    setWindowIcon(QIcon(":/Logo.png"));

    setStyleSheet(
        "QPushButton {"
        "    background-color: #E6E6E6;"
        "    border: 1px solid #888888;"
        "    border-bottom: 3px solid #666666;"
        "    border-radius: 5px;"
        "    padding: 4px 10px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #F2F2F2;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #D0D0D0;"
        "    border-top: 3px solid #666666;"
        "    border-bottom: 1px solid #888888;"
        "    padding-top: 6px;"
        "    padding-bottom: 2px;"
        "}"
        "QPushButton:disabled {"
        "    color: #999999;"
        "    background-color: #DDDDDD;"
        "    border-color: #BBBBBB;"
        "}"               

        "QGroupBox {"
        "    font-weight: bold;"
        "    border: 1px solid #888888;"
        "    border-radius: 6px;"
        "    margin-top: 8px;"
        "    padding-top: 8px;"
        "}"

        "QGroupBox::title {"
        "    subcontrol-origin: margin;"
        "    subcontrol-position: top left;"
        "    left: 10px;"
        "    padding: 0px 5px;"
        "}"     
    
    );

    // ----------------- CENTRAL WIDGET -----------------
    QWidget *central_widget = new QWidget(this);
    QVBoxLayout *main_layout = new QVBoxLayout(central_widget);

    // ----------------- CONNECTION -----------------
    QGroupBox *connection_group = new QGroupBox("Connection");
    QHBoxLayout *connection_layout = new QHBoxLayout(connection_group);

    QLabel *ip_label = new QLabel("IP:");
    ip_edit = new QLineEdit("192.168.137.200");
    ip_edit->setFixedWidth(150);

    QLabel *port_label = new QLabel("Port:");
    port_edit = new QLineEdit("9999");
    port_edit->setFixedWidth(60);

    connect_button = new QPushButton("Connect");
    connect_button->setFixedWidth(90);

    QLabel *status_title = new QLabel("Status:");
    status_label = new QLabel("Disconnected");
    status_label->setStyleSheet("QLabel { color: red; }");

    connection_layout->addWidget(ip_label);
    connection_layout->addWidget(ip_edit);
    connection_layout->addWidget(port_label);
    connection_layout->addWidget(port_edit);
    connection_layout->addWidget(connect_button);
    connection_layout->addWidget(status_title);
    connection_layout->addWidget(status_label);
    connection_layout->addStretch();

    main_layout->addWidget(connection_group);


    connect(connect_button,
            &QPushButton::clicked,
            this,
            &MainWindow::onConnectButtonClicked);

    connect(tcp_socket,
            &QTcpSocket::connected,
            this,
            &MainWindow::onSocketConnected);

    connect(tcp_socket,
            &QTcpSocket::disconnected,
            this,
            &MainWindow::onSocketDisconnected);

    connect(tcp_socket,
            &QTcpSocket::errorOccurred,
            this,
            &MainWindow::onSocketError);

    connect(tcp_socket,
            &QTcpSocket::readyRead,
            this,
            &MainWindow::onSocketReadyRead);

    // ----------------- COMMAND -----------------
    QGroupBox *command_group = new QGroupBox("Command");
    QHBoxLayout *command_layout = new QHBoxLayout(command_group);

    command_edit = new QLineEdit();

    send_button = new QPushButton("Send");
    command_clear_button = new QPushButton("Clear");

    QVBoxLayout *command_button_layout = new QVBoxLayout();
    command_button_layout->addWidget(send_button);
    command_button_layout->addWidget(command_clear_button);

    command_status_label = new QLabel();
    command_status_label->setFixedWidth(120);

    command_layout->addWidget(command_edit);
    command_layout->addLayout(command_button_layout);
    command_layout->addWidget(command_status_label);

    main_layout->addWidget(command_group);


    connect(send_button,
            &QPushButton::clicked,
            this,
            &MainWindow::onSendButtonClicked);

    connect(command_edit,
            &QLineEdit::returnPressed,
            this,
            &MainWindow::onSendButtonClicked);

    connect(command_clear_button,
            &QPushButton::clicked,
            this,
            &MainWindow::onCommandClearButtonClicked);

    // ----------------- RESPONSE -----------------

    QGroupBox *response_group = new QGroupBox("Response");
    QVBoxLayout *response_layout = new QVBoxLayout(response_group);

    response_label = new QTextEdit();
    response_label->setMinimumHeight(80);
    response_label->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    response_label->setLineWrapMode(QTextEdit::WidgetWidth);

    response_clear_button = new QPushButton("Clear");
    response_clear_button->setFixedWidth(80);

    connect(response_clear_button,
            &QPushButton::clicked,
            this,
            &MainWindow::onResponseClearButtonClicked);

    QHBoxLayout *response_button_layout = new QHBoxLayout();
    response_button_layout->addStretch();
    response_button_layout->addWidget(response_clear_button);

    response_layout->addWidget(response_label);
    response_layout->addLayout(response_button_layout);

    main_layout->addWidget(response_group);

   
    // ----------------- AVAILABLE COMMAND -----------------
    QGroupBox *available_command_group =
        new QGroupBox("Available Command");

    QGridLayout *available_command_layout =
        new QGridLayout(available_command_group);

    const QStringList available_commands =
    {
        "INS", "STP", "SAH", "SHC", "SHC?",
        "SVO", "SVF", "CAL", "DSC", "VLS",
        "MOV", "MRV", "MSV", "MSR", "MPV",
        "MPR", "MOV?", "POS?", "PMS?", "SPI",
        "SPI?", "FRS?", "DFRS", "FLM", "BKN?"
    };

    for (int i = 0; i < available_commands.size(); ++i)
    {
        QLabel *command_label =
            new QLabel(available_commands[i]);

        command_label->setTextInteractionFlags(
            Qt::TextSelectableByMouse |
            Qt::TextSelectableByKeyboard);

        command_label->setAlignment(Qt::AlignCenter);

        available_command_layout->addWidget(
            command_label,
            i / 5,
            i % 5);
    }

    main_layout->addWidget(available_command_group);


    setCentralWidget(central_widget);

    resize(600, 500);
}

MainWindow::~MainWindow()
{
    if (tcp_socket->state() != QAbstractSocket::UnconnectedState)
    {
        tcp_socket->disconnectFromHost();
    }
    delete ui;
}

void MainWindow::onConnectButtonClicked()
{
    if (tcp_socket->state() == QAbstractSocket::ConnectedState)
    {
        tcp_socket->disconnectFromHost();
        return;
    }

    if (tcp_socket->state() == QAbstractSocket::ConnectingState)
    {
        return;
    }

    const QString ip_address = ip_edit->text().trimmed();
    const quint16 port = port_edit->text().toUShort();

    status_label->setText("Connecting...");
    status_label->setStyleSheet("QLabel { color: orange; }");

    ip_edit->setEnabled(false);
    port_edit->setEnabled(false);

    connect_button->setEnabled(false);

    tcp_socket->connectToHost(ip_address, port);
}

void MainWindow::onSocketConnected()
{
    status_label->setText("Connected");
    status_label->setStyleSheet("QLabel { color: green; }");

    connect_button->setText("Disconnect");
    connect_button->setEnabled(true);
}

void MainWindow::onSocketDisconnected()
{
    response_buffer.clear();
    status_label->setText("Disconnected");
    status_label->setStyleSheet("QLabel { color: red; }");

    connect_button->setText("Connect");
    connect_button->setEnabled(true);

    ip_edit->setEnabled(true);
    port_edit->setEnabled(true);
}

void MainWindow::onSocketError(
    QAbstractSocket::SocketError socket_error)
{
    Q_UNUSED(socket_error);

    status_label->setText("Connection Lost");
    status_label->setStyleSheet("QLabel { color: red; }");

    connect_button->setText("Connect");
    connect_button->setEnabled(true);

    ip_edit->setEnabled(true);
    port_edit->setEnabled(true);
}

void MainWindow::onSendButtonClicked()
{
    if (tcp_socket->state() != QAbstractSocket::ConnectedState)
    {
        return;
    }

    const QString command = command_edit->text();

    if (command.isEmpty())
    {
        return;
    }

    const QByteArray data = command.toUtf8() + "\r\n";

    response_label->clear();
    response_buffer.clear();

    tcp_socket->write(data);

    command_status_label->setText("Command Sent Out");
    command_status_label->setStyleSheet("QLabel { color: blue; }");

    QTimer::singleShot(1000, this, [this]()
    {
        command_status_label->clear();
    });
}

void MainWindow::onSocketReadyRead()
{
    response_buffer.append(tcp_socket->readAll());

    while (response_buffer.contains("\r\n"))
    {
        const int line_end =
            response_buffer.indexOf("\r\n");

        const QByteArray line =
            response_buffer.left(line_end);

        response_buffer.remove(
            0,
            line_end + 2);

        QString response_text =
            QString::fromUtf8(line).trimmed();

        if (response_text.isEmpty())
        {
            continue;
        }

        const bool is_error =
            response_text.startsWith("[ERROR]");

        if (is_error)
        {
            response_text =
                response_text.mid(
                    QString("[ERROR]").length()).trimmed();

            response_label->append(response_text);

            response_label->setStyleSheet(
                "QTextEdit { color: red; }");
        }
        else
        {
            response_label->append(response_text);

            response_label->setStyleSheet(
                "QTextEdit { color: blue; }");
        }
    }
}

void MainWindow::onCommandClearButtonClicked()
{
    command_edit->clear();
}

void MainWindow::onResponseClearButtonClicked()
{
    response_label->clear();
    response_buffer.clear();
}