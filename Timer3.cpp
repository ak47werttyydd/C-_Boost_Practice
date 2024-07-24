//
// Created by ruochen on 2024-07-23.
//

#include "Timer3.h"
//To implement a repeating timer using asio you need to change the timer's expiry time in your completion handler, and to then start a new asynchronous wait. Obviously this means that the completion handler will need to be able to access the timer object.
//so the 2nd arg is a pointer to a timer object
//the 3rd arg is a counter so that we can stop the program when the timer fires for the sixth time
void print(const boost::system::error_code& /*e*/,
           boost::asio::steady_timer* t, int* count)
{
    if (*count < 5)
    {
        std::cout << *count << std::endl;
        ++(*count);

        //+1s
        t->expires_at(t->expiry() + boost::asio::chrono::seconds(1));

        //start a new asynchronous wait on the timer
        //std::bind() binds the 2nd(t) and 3rd args(count) to the print function, the 1st arg is not bound and placed by a placeholder. Returns a new function object that takes the 1st arg (error code)
        t->async_wait(std::bind(print,
                                boost::asio::placeholders::error, t, count));
    }
}

int main()
{
    boost::asio::io_context io;
    int count = 0;
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(1));
    t.async_wait(std::bind(print,
                           boost::asio::placeholders::error, &t, &count));
    io.run();