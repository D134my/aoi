#include "aoi.hpp"

Aoi::Aoi(boost::asio::io_context &ioc)
    : _ioc(ioc), _acceptor(new boost::asio::ip::tcp::acceptor(ioc)) {}

Aoi::Aoi(boost::asio::io_context &ioc, unsigned short port)
    : _ioc(ioc), _acceptor(new boost::asio::ip::tcp::acceptor(ioc)),
      _port(port) {}

void Aoi::set_port(unsigned short port) noexcept { _port = port; }

bool Aoi::checkOpenPorts() {

  try {

    std::cout << "scanning " << _port << std::endl;
    _acceptor->open(boost::asio::ip::tcp::v4());
    _acceptor->bind({boost::asio::ip::tcp::v4(), _port});

    std::cout << "port " << _port << " is not open, you can connect to it\n";
    return true;
  } catch (std::exception &error) {
    std::cerr << "port " << _port << " is in use \n";
    std::cerr << "open port Error : " << error.what() << '\n';
    return false;
  }
}