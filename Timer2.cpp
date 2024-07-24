//
/*Using Timer asynchronously*/
//Using asio's asynchronous functionality means supplying a completion token, which determines how the result will be delivered to a completion handler when an asynchronous operation completes

#include "Timer2.h"
//call print function when an asynchronous operation completes
//handler should meet the signature "void handler(const boost::system::error_code&);"
void print(const boost::system::error_code& /*e*/)
{
    std::cout << "Hello, world, this is Timer2!" << std::endl;
}

int main() {
    boost::asio::io_context io;
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));

    //perform an asynchronous wait and call the print function when the timer expires
    t.async_wait(&print);
    //In C++, passing the name of a function without parentheses is equivalent to passing a function pointer. However, for clarity and explicitness, especially when dealing with function pointers and callbacks, it is common practice to use the address-of operator (&) to explicitly denote that you are passing a pointer to a function.

    //completion handlers will only be called from threads that are currently calling boost::asio::io_context::run(). Therefore unless the boost::asio::io_context::run() function is called the completion handler for the asynchronous wait completion will never be invoked.
    io.run();
    //The boost::asio::io_context::run() function will also continue to run while there is still "work" to do. In this example, the work is the asynchronous wait on the timer, so the call will not return until the timer has expired and the completion handler has returned.


    return 0;
}