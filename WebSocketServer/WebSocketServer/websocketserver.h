#ifndef WEBSOCKETSERVER_H
#define WEBSOCKETSERVER_H

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <iostream>
#include <string>
#include <thread>

namespace beast = boost::beast;
namespace websocket = beast::websocket;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;
using string = std::string;


class WebSocketServer
{
public:
    WebSocketServer();
    WebSocketServer(string address,unsigned short port);


    void run();


private:
    net::ip::address address;
    unsigned short port;


};

#endif // WEBSOCKETSERVER_H
