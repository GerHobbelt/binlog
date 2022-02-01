#include <binlog/binlog.hpp>

//[setmin
#include <binlog/Severity.hpp>
//]

#include <iostream>

#include "monolithic_examples.h"


static int f()
{
  BINLOG_ERROR("Unexpected call to f()");
  return 0;
}



#if defined(BUILD_MONOLITHIC)
#define main(cnt, arr)      binlog_test_severity_control_main(cnt, arr)
#endif

int main(int argc, const char** argv)
{
  binlog::Session& session = binlog::default_session();
  BINLOG_TRACE("Default");
  // Outputs: TRAC Default

  session.setMinSeverity(binlog::Severity::no_logs);
  BINLOG_CRITICAL("Disabled");

  session.setMinSeverity(binlog::Severity::critical);
  BINLOG_CRITICAL("Enabled");
  BINLOG_ERROR("Disabled");
  // Outputs: CRIT Enabled

  session.setMinSeverity(binlog::Severity::error);
  BINLOG_ERROR("Enabled");
  BINLOG_WARN("Disabled");
  // Outputs: ERRO Enabled

  session.setMinSeverity(binlog::Severity::warning);
  BINLOG_WARN("Enabled");
  BINLOG_INFO("Disabled");
  // Outputs: WARN Enabled

  session.setMinSeverity(binlog::Severity::info);
  BINLOG_INFO("Enabled");
  BINLOG_DEBUG("Disabled");
  // Outputs: INFO Enabled

  session.setMinSeverity(binlog::Severity::debug);
  BINLOG_DEBUG("Enabled");
  BINLOG_TRACE("Disabled");
  // Outputs: DEBG Enabled

  session.setMinSeverity(binlog::Severity::trace);
  BINLOG_TRACE("Enabled");
  // Outputs: TRAC Enabled

  // Arguments of disabled severities are not evaluated:

  //[setmin

  session.setMinSeverity(binlog::Severity::warning);
  // trace, debug, info severities are disabled
  //]

  //[noeval
  // after setting min severity to warning above:
  BINLOG_INFO("Call f: {}", f()); // f will not be called
  //]

  binlog::consume(std::cout);
  return 0;
}
