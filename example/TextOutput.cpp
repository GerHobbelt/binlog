#include <binlog/TextOutputStream.hpp> // requires binlog library to be linked
#include <binlog/binlog.hpp>

#include <iostream>

#include "monolithic_examples.h"



#if defined(BUILD_MONOLITHIC)
#define main(cnt, arr)      binlog_example_text_output_main(cnt, arr)
#endif

int main(int argc, const char** argv)
{
  BINLOG_INFO("Hello Text Output!");

  binlog::TextOutputStream output(std::cout);
  binlog::consume(output);

  return 0;
}
