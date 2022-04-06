#include "client.h"

Client::Client(QObject *parent)
    : QObject{parent}
{
    connect(&socket, &QTcpSocket::connected, this, &Client::Connected);
    connect(&socket, &QTcpSocket::disconnected, this, &Client::Disconnected);
    connect(&socket, &QTcpSocket::stateChanged, this, &Client::StateChanged);
    connect(&socket, &QTcpSocket::readyRead, this, &Client::ReadyRead);
    connect(&socket, &QAbstractSocket::errorOccurred, this, &Client::Error);
}

void Client::ConnectToHost()
{
    if (socket.isOpen()) {
        Disconnect();
    }
    qInfo() << "Connecting to: " << tcp_connection_settings::host << ":" << tcp_connection_settings::port;
    socket.connectToHost(tcp_connection_settings::host, tcp_connection_settings::port);
}

void Client::Disconnect()
{
    socket.close();
}

void Client::Connected()
{
    qInfo() << "Connected";
    qInfo() << "Sending test message:";
    socket.write("Test message");
}

void Client::Disconnected()
{
    qInfo() << "Disconnected";
}

void Client::Error(QAbstractSocket::SocketError socketError)
{
    qInfo() << "Error: " << socketError << " " << socket.errorString();
}

void Client::StateChanged(QAbstractSocket::SocketState socketState)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketState>();
    qInfo() << "State changed: " << metaEnum.valueToKey(socketState);
}

void Client::ReadyRead()
{
    qInfo() << "Data from: " << sender() << " bytes: " << socket.bytesAvailable();
    qInfo() << "Data: " << socket.readAll();
}
