#include <binlog/binlog.hpp>

#include <iostream>

#include "monolithic_examples.h"



#if defined(BUILD_MONOLITHIC)
#define main(cnt, arr)      binlog_test_named_writers_main(cnt, arr)
#endif

int main(int argc, const char** argv)
{
  binlog::Session session;
  binlog::SessionWriter writer(session);

  //[setName
  writer.setName("w1");
  BINLOG_INFO_W(writer, "Hello named writer");
  // Outputs: w1 Hello named writer
  //]

  binlog::SessionWriter writer2(session);
  writer2.setName("w2");
  BINLOG_INFO_W(writer2, "Hello other named writer");
  // Outputs: w2 Hello other named writer

  session.consume(std::cout);
  return 0;
}
