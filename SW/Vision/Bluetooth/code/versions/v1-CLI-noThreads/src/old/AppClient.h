/**
 * @file AppClient.h
 * @author Jose Pires
 * @date 04-06-2019
 *
 * @brief Interface for Server app for Client/server
 */

#ifndef APPSERVER_H
#define APPSERVER_H
#include "Database.h"
#include "RFCommSocketServer.h"

class AppServer{
    Database *db;
    RFCommSocketServer *serv;
    string hostname;
/* Handlers */
    void connection_CB(int port);
    void send_CB(const string &s);
    void recv_CB();
    void help_CB();
public:
/**
 * @brief Constructs the App Server
 */
AppServer();

/**
 * @brief Executes the AppServer event loop
 */
void exec();
};


#endif // APPSERVER_H
