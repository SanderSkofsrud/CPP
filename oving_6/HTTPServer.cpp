#include <boost/asio.hpp>
#include <iostream>

using namespace std;
using namespace boost::asio::ip;

class SimpleServer {
private:
    class Connection {
    public:
        tcp::socket socket;
        Connection(boost::asio::io_service &io_service) : socket(io_service) {}
    };

    boost::asio::io_service io_service;
    tcp::endpoint endpoint;
    tcp::acceptor acceptor;

    string main_page() {
        return "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\nDette er hovedsiden";
    }

    string en_side_page() {
        return "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\nDette er en side";
    }

    string not_found_page() {
        return "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n404 Not Found";
    }

    void handle_request(shared_ptr<Connection> connection) {
        auto read_buffer = make_shared<boost::asio::streambuf>();
        async_read_until(connection->socket, *read_buffer, "\r\n",
                         [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
            if (!ec) {
                istream read_stream(read_buffer.get());
                string request;
                getline(read_stream, request);

                auto write_buffer = make_shared<boost::asio::streambuf>();
                ostream write_stream(write_buffer.get());

                if (request.find("GET /en_side HTTP/1.1") != string::npos) {
                    write_stream << en_side_page();
                } else if (request.find("GET / HTTP/1.1") != string::npos) {
                    write_stream << main_page();
                } else {
                    write_stream << not_found_page();
                }

                async_write(connection->socket, *write_buffer,
                            [this, connection, write_buffer](const boost::system::error_code &ec, size_t) {
                    connection->socket.close();
                });
            }
        });
    }

    void accept() {
        auto connection = make_shared<Connection>(io_service);
        acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
            if (!ec) handle_request(connection);
            accept();
        });
    }

public:
    SimpleServer() : endpoint(tcp::v4(), 8080), acceptor(io_service, endpoint) {}

    void start() {
        accept();
        io_service.run();
    }
};

int main() {
    SimpleServer server;
    cout << "Starting server at http://localhost:8080" << endl;
    server.start();
}
