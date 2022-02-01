#include <binlog/binlog.hpp>

#include <iostream>

#include <string>
#include <tuple>
#include <utility> // pair

#include "monolithic_examples.h"



#if defined(BUILD_MONOLITHIC)
#define main(cnt, arr)      binlog_test_tuples_main(cnt, arr)
#endif

int main(int argc, const char** argv)
{
  std::tuple<> empty;
  BINLOG_INFO("Empty tuple: {}", empty);
  // Outputs: Empty tuple: ()

  //[stdtup
  std::pair<int, char> p{1, 'a'};
  std::tuple<std::string, bool, int> t{"foo", true, 2};
  BINLOG_INFO("Pair: {}, Tuple: {}", p, t);
  // Outputs: Pair: (1, a), Tuple: (foo, true, 2)
  //]

  binlog::consume(std::cout);
  return 0;
}
