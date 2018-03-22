#include <zmq.hpp>
#include <zmq.h>
#include <iostream>
// #include <algorithm>   

using namespace std;

int main(int argc, char *argv[])
{
    zmq::context_t context(1);
    std::cout << "Sending message to NM Server…\n"
              << std::endl; 

    // Socket to subscribe to server too. Although in first instance
    // I don't need receive messages by the moment
    zmq::socket_t subscriber(context, ZMQ_SUB);
    subscriber.connect("tcp://localhost:5557");
    subscriber.setsockopt(ZMQ_SUBSCRIBE, "", 0);

    //  Socket to send messages to
    zmq::socket_t sender(context, ZMQ_PUSH);
    sender.connect("tcp://localhost:5558");

    string firstMessage = "Hello peers";

    while(1) {
        zmq::message_t message(firstMessage.size()+1);
        //copy_n(firstMessage.c_str(), firstMessage.size()+1, reinterpret_cast<char *>(message.data()));
        memcpy(message.data(), firstMessage.c_str(), firstMessage.size()+1);
        sender.send(message);
    }
    return 0;
}


