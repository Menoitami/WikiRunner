#include "websocketserver.h"

WebSocketServer::WebSocketServer() {}




WebSocketServer::WebSocketServer(string address,unsigned short port){

    this->address = net::ip::make_address(address);
    this->port = 8083;


}
