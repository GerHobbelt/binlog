#include <binlog/binlog.hpp>

//[cstr
#include <binlog/char_ptr_is_string.hpp>
//]

#include <cerrno> // EBADF
#include <iostream>

#include "monolithic_examples.h"


// Something silly, that returns platform and locale independent
// char* error message, unlike strerror
/* const */ char g_errormsg[] = "Bad file descriptor";
/* const */ char* geterror(int) { return g_errormsg; }



#if defined(BUILD_MONOLITHIC)
#define main(cnt, arr)      binlog_test_cstrings_main(cnt, arr)
#endif

int main(int argc, const char** argv)
{
  //[cstr

  char* error = geterror(EBADF);
  BINLOG_INFO("Error: {}", error);
  // Outputs: Error: Bad file descriptor
  //]

  binlog::consume(std::cout);
  return 0;
}
