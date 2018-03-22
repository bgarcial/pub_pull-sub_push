#include <zmq.hpp>
#include <zmq.h>
#include <iostream>
#include "zhelpers.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    zmq::context_t context(1);
    /*
    std::cout << "Sending message to NM Server…\n" << std::endl; */

    zmq::socket_t subscriber(context, ZMQ_SUB);
    subscriber.connect("tcp://localhost:5557");
    subscriber.setsockopt(ZMQ_SUBSCRIBE, "", 0);

    while (1)
    {
        //  Wait for next request from client
        std::string string = s_recv(subscriber);

        std::cout << "Received request: " << string << std::endl;

        // Do some 'work'
        sleep(1);

        //  Send reply back to client
        // s_send(responder, "Hola soy un responder 1");
    }
}