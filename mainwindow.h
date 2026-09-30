#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void onConnectButtonClicked();
    void onSocketConnected();
    void onSocketDisconnected();
    void onSocketError(QAbstractSocket::SocketError socket_error);
    void onSendButtonClicked();
    void onSocketReadyRead();
    void onCommandClearButtonClicked();
    void onResponseClearButtonClicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *tcp_socket;
    QLineEdit *ip_edit;
    QLineEdit *port_edit;
    QPushButton *connect_button;
    QLabel *status_label;
    QLabel *command_status_label;
    QPushButton *command_clear_button;
    QLineEdit *command_edit;
    QPushButton *send_button;
    QTextEdit *response_label;
    QPushButton *response_clear_button;
    QByteArray response_buffer;

};
#endif // MAINWINDOW_H
