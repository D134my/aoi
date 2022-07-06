#include "aoi.hpp"
#include <cstdlib>
#include <gtest/gtest.h>

#define GTEST_COUT std::cerr << "[          ] [ INFO ] "

int _argc;
char **_argv;

TEST(AoiTEST, CHECKOPENPORT) {

  if (_argc == 2) {
    boost::asio::io_context ioc;
    GTEST_COUT << "port " << _argv[1] << " should scan \n";
    Aoi aoi(ioc, std::atoi(_argv[1]));
    EXPECT_TRUE(aoi.checkOpenPorts());
  } else if (_argc == 3) {
    GTEST_COUT << "all ports between " << _argv[1] << '-' << _argv[2]
               << " should scan \n";

    auto const start_port = std::atoi(_argv[1]);
    auto const end_port = std::atoi(_argv[2]);

    ASSERT_LT(start_port, end_port);

    for (auto i{start_port}; i <= end_port; ++i) {
      boost::asio::io_context ioc;
      Aoi aoi(ioc);
      EXPECT_NO_THROW(aoi.set_port(i));
      EXPECT_TRUE(aoi.checkOpenPorts());
    }
  } else {
    GTEST_COUT << "./aoi port or ./aor start_port end_port\n";
  }
}

int main(int argc, char **argv) {

  testing::InitGoogleTest(&argc, argv);

  _argc = argc;
  _argv = argv;

  return RUN_ALL_TESTS();
}
