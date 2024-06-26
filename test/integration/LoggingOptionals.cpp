//[stdopt
#include <binlog/adapt_stdoptional.hpp> // must be included to log std::optional, requires C++17
//]

#include <binlog/binlog.hpp>

#include <iostream>
#include <optional>

#include "monolithic_examples.h"



#if defined(BUILD_MONOLITHIC)
#define main(cnt, arr)      binlog_test_optionals_main(cnt, arr)
#endif

int main(int argc, const char** argv)
{
  // Std optional - loggable if adapt_stdoptional.hpp is included

  //[stdopt

  std::optional<int> opt(123);
  std::optional<int> emptyOpt;
  BINLOG_INFO("Optionals: {} {}", opt, emptyOpt);
  // Outputs: Optionals: 123 {null}
  //]

  binlog::consume(std::cout);
  return 0;
}
