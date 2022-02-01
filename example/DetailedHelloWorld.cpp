#include <binlog/Session.hpp>
#include <binlog/SessionWriter.hpp>
#include <binlog/advanced_log_macros.hpp>

#include <fstream>
#include <iostream>

#include "monolithic_examples.h"



#if defined(BUILD_MONOLITHIC)
#define main(cnt, arr)      binlog_example_detailed_hello_main(cnt, arr)
#endif

int main(int argc, const char** argv)
{
  binlog::Session session;
  binlog::SessionWriter writer(session);

  BINLOG_INFO_W(writer, "Hello {}!", "World");

  std::ofstream logfile("hello.blog", std::ofstream::out|std::ofstream::binary);
  session.consume(logfile);

  if (! logfile)
  {
    std::cerr << "Failed to write hello.blog\n";
    return 1;
  }

  std::cout << "Binary log written to hello.blog\n";
  return 0;
}
