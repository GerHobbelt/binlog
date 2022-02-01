#include <binlog/binlog.hpp>

//[c
#include <binlog/advanced_log_macros.hpp>
//]

#include <iostream>

#include "monolithic_examples.h"



#if defined(BUILD_MONOLITHIC)
#define main(cnt, arr)      binlog_test_categories_main(cnt, arr)
#endif

int main(int argc, const char** argv)
{
  binlog::default_thread_local_writer().setName({});

  //[c

  BINLOG_INFO_C(my_category, "This is a categorized event");
  // Outputs: my_category  This is a categorized event
  //]

  binlog::SessionWriter writer(binlog::default_session());
  writer.setName("W1");

  //[wc
  BINLOG_INFO_WC(writer, my_category, "My writer, my category");
  // Outputs: my_category W1 My writer, my category
  //]

  binlog::consume(std::cout);
  return 0;
}
