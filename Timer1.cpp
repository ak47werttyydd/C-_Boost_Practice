//
/*Using Timer synchronously*/
//

#include "Timer1.h"

int main()
{
    //All programs that use asio need to have at least one I/O execution context, such as an io_context or thread_pool object
    boost::asio::thread_pool pool(4);
    boost::asio::io_context io; //I/O execution context provides access to I/O functionality.

    //timer: first arg: reference to an execution context (io); second arg: expire 5 seconds from now.
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));

    //blocking wait for the timer to expire. wait() will not return until the timer has expired, 5 seconds after it was created (i.e. not from when the wait starts).
    t.wait();

    std::cout << "Hello, world!" << std::endl;
    return 0;
}