// Generate a large logfile, to measure bread performance

#include <binlog/binlog.hpp>

#include <iostream>
#include <string>
#include <vector>

#include "monolithic_examples.h"



#if defined(BUILD_MONOLITHIC)
#define main(cnt, arr)      binlog_performance_large_log_file_main(cnt, arr)
#endif

int main(int argc, const char** argv)
{
  BINLOG_INFO("Hello Large Logfile");

  std::size_t size = 0;
  std::size_t targetSize = 300UL * 1024UL * 1024UL;

  const std::vector<int> numbers{1,2,3,4,5,6,7,8};

  while (size < targetSize)
  {
    // duplicate code, to artificially increase the number of event sources
    BINLOG_INFO("int {} bool {} char {}", 123, true, 'X');
    BINLOG_DEBUG("Hello {}", "string");
    BINLOG_DEBUG("More strings {} {} abc {}", "aaaaaaaaaaa", "bb", "ccccccccccccccccccccccccc");

    BINLOG_INFO("int {} bool {} char {}", 123, true, 'X');
    BINLOG_DEBUG("Hello {}", "string");
    BINLOG_DEBUG("More strings {} {} abc {}", "aaaaaaaaaaa", "bb", "ccccccccccccccccccccccccc");

    BINLOG_INFO("int {} bool {} char {}", 123, true, 'X');
    BINLOG_DEBUG("Hello {}", "string");
    BINLOG_DEBUG("More strings {} {} abc {}", "aaaaaaaaaaa", "bb", "ccccccccccccccccccccccccc");

    BINLOG_INFO("int {} bool {} char {}", 123, true, 'X');
    BINLOG_DEBUG("Hello {}", "string");
    BINLOG_DEBUG("More strings {} {} abc {}", "aaaaaaaaaaa", "bb", "ccccccccccccccccccccccccc");

    BINLOG_INFO("int {} bool {} char {}", 123, true, 'X');
    BINLOG_DEBUG("Hello {}", "string");
    BINLOG_DEBUG("More strings {} {} abc {}", "aaaaaaaaaaa", "bb", "ccccccccccccccccccccccccc");

    BINLOG_INFO("int {} bool {} char {}", 123, true, 'X');
    BINLOG_DEBUG("Hello {}", "string");
    BINLOG_DEBUG("More strings {} {} abc {}", "aaaaaaaaaaa", "bb", "ccccccccccccccccccccccccc");

    BINLOG_INFO("int {} bool {} char {}", 123, true, 'X');
    BINLOG_DEBUG("Hello {}", "string");
    BINLOG_DEBUG("More strings {} {} abc {}", "aaaaaaaaaaa", "bb", "ccccccccccccccccccccccccc");

    BINLOG_INFO("int {} bool {} char {}", 123, true, 'X');
    BINLOG_DEBUG("Hello {}", "string");
    BINLOG_DEBUG("More strings {} {} abc {}", "aaaaaaaaaaa", "bb", "ccccccccccccccccccccccccc");

    BINLOG_INFO("int {} bool {} char {}", 123, true, 'X');
    BINLOG_DEBUG("Hello {}", "string");
    BINLOG_DEBUG("More strings {} {} abc {}", "aaaaaaaaaaa", "bb", "ccccccccccccccccccccccccc");

    BINLOG_INFO("int {} bool {} char {}", 123, true, 'X');
    BINLOG_DEBUG("Hello {}", "string");
    BINLOG_DEBUG("More strings {} {} abc {}", "aaaaaaaaaaa", "bb", "ccccccccccccccccccccccccc");

    BINLOG_INFO("int {} bool {} char {}", 123, true, 'X');
    BINLOG_DEBUG("Hello {}", "string");
    BINLOG_DEBUG("More strings {} {} abc {}", "aaaaaaaaaaa", "bb", "ccccccccccccccccccccccccc");

    BINLOG_INFO("Look, numbers: {}", numbers);

    const auto result = binlog::consume(std::cout);
    size += result.bytesConsumed;
  }

  return 0;
}
