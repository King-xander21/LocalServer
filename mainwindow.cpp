#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkInterface>
#include <QMimeDatabase>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = new QTcpServer(this);
    connect(server, &QTcpServer::newConnection, this, &MainWindow::handleNewConnection);
    ui->HostPath->setPlaceholderText(".../index.html");
    ui->linePort->setPlaceholderText("port:8080");
}

void MainWindow::on_btnStart_clicked()
{
    int port = ui->linePort->text().toInt();

    if (server->listen(QHostAddress::Any, port))
    {
        ui->lblStatus->setText("Online");
        ui->lblStatus->setStyleSheet("color: greeen");

        // Show local ip address
        QString ipAddress;
        for (const QHostAddress &address : QNetworkInterface::allAddresses())
        {
            if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress::LocalHost)
            {
                ipAddress = address.toString();
            }
            ui->logOutput->append("Server started at http://" + ipAddress + ":" + QString::number(port));
        }
    }
}

void MainWindow::on_btnStop_clicked()
{
    server->close();
    ui->lblStatus->setText("Status: Offline");
    ui->lblStatus->setStyleSheet("color: red;");
    ui->logOutput->append("Server stopped.");
}

void MainWindow::handleNewConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();
    // ui->logOutput->append("New Connection from: "+ socket->peerAddress().toString());

    // connect(socket, &QTcpSocket::readyRead, [this, socket]()
    // {
    //     socket->readAll(); // Consume the request
    //     QString response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"
    //                        "<h1>Qt Server is hosting Flutter!</h1>";
    //     socket->write(response.toUtf8());
    //     socket->disconnectFromHost();
    // });

    connect(socket, &QTcpSocket::readyRead, [this, socket](){
        QString request = socket->readAll();

        // Extracting files from the GET request
        QStringList lines = request.split("\n");
        if (lines.isEmpty()) return;
        
        QString path = lines[0].split(" ")[1];
        if (path == "/") path = "/index.html"; // default to index.html

        // Setting Path to web folder
        QString fullPath = "/media/alexander/10165AA9165A8F98/Linux/FlutterPrj/CleaningApp/cleaning/build/web/" + path;
        // QString fullPath = ui->HostPath->text().trimmed();
        // QString fullFilePath = fullPath + path;
        QFile file(fullPath);

        if (file.open(QIODevice::ReadOnly))
        {   
            QByteArray content = file.readAll();

            // Detecting file type
            QMimeDatabase db;
            QString mimeType = db.mimeTypeForFile(fullPath).name();

            // 4. Send HTTP Header + Content
            socket->write("HTTP/1.1 200 OK\r\n");
            socket->write(QString("Content-Type: %1\r\n").arg(mimeType).toUtf8());
            socket->write(QString("Content-Length: %1\r\n").arg(content.size()).toUtf8());
            socket->write("Access-Control-Allow-Origin: *\r\n"); // Fixes Flutter CORS
            socket->write("\r\n");
            socket->write(content);
        }
        else 
        {
            socket->write("HTTP/1.1 404 Not Found\r\n\r\n");
        }
        socket->disconnectFromHost();
    });
}


MainWindow::~MainWindow()
{
    delete ui;
}
