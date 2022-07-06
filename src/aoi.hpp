#ifndef __aoi_scanner__
#define __aoi_scanner__

#include <boost/asio.hpp>
#include <iostream>
#include <memory>

class Aoi {
public:
  Aoi(boost::asio::io_context &ioc);
  Aoi(boost::asio::io_context &ioc, unsigned short port);

  void set_port(unsigned short port) noexcept;
  bool checkOpenPorts();

private:
  boost::asio::io_context &_ioc;
  unsigned short _port;
  std::unique_ptr<boost::asio::ip::tcp::acceptor> _acceptor;
};

#endif