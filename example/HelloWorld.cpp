//[hello
#include <binlog/binlog.hpp>
//]

#include <fstream>
#include <iostream>

#include "monolithic_examples.h"

//[hello


#if defined(BUILD_MONOLITHIC)
#define main(cnt, arr)      binlog_example_hello_main(cnt, arr)
#endif

int main(int argc, const char** argv)
{
  BINLOG_INFO("Hello {}!", "World");

  std::ofstream logfile("hello.blog", std::ofstream::out|std::ofstream::binary);
  binlog::consume(logfile);
//]

  if (! logfile)
  {
    std::cerr << "Failed to write hello.blog\n";
    return 1;
  }

  std::cout << "Binary log written to hello.blog\n";
  return 0;

//[hello
}
//]
