
#if !defined(BUILDING_BINLOG_TOOLS)
#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest/doctest.h>
#endif

#define BUILD_MONOLITHIC 1
#include "monolithic_examples.h"

#if defined(BUILDING_BINLOG_TOOLS)
#define USAGE_NAME   "binlog_tools"
#else
#define USAGE_NAME   "binlog_tests"
#endif

#include "monolithic_main_internal_defs.h"

MONOLITHIC_CMD_TABLE_START()

#if defined(BUILDING_BINLOG_TOOLS)

	{ "bread", {.fa = binlog_bread_main } },
	{ "brecovery", {.fa = binlog_brecovery_main } },
	{ "ex_consumeloop", {.fa = binlog_example_consume_loop_main } },
	{ "ex_detailed_hello", {.fa = binlog_example_detailed_hello_main } },
	{ "ex_hello", {.fa = binlog_example_hello_main } },
	{ "ex_logrotation", {.fa = binlog_example_log_rotation_main } },
	{ "ex_multi_output", {.fa = binlog_example_multi_output_main } },
	{ "ex_textoutput", {.fa = binlog_example_text_output_main } },
	{ "ex_clock", {.fa = binlog_example_tsc_clock_main } },
	{ "generate_foreach", {.fa = binlog_generate_foreach_main } },

#endif

#if defined(BUILDING_BINLOG_TESTS)

	{ "test_categories", {.fa = binlog_test_categories_main } },
	{ "test_integration", {.fa = binlog_test_integration_main } },
	{ "test_logging", {.fa = binlog_test_logging_main } },
	{ "test_adapted_structs", {.fa = binlog_test_adapted_structs_main } },
	{ "test_boost_types", {.fa = binlog_test_boost_types_main } },
	{ "test_containers", {.fa = binlog_test_containers_main } },
	{ "test_cstrings", {.fa = binlog_test_cstrings_main } },
	{ "test_duration", {.fa = binlog_test_duration_main } },
	{ "test_enums", {.fa = binlog_test_enums_main } },
	{ "test_errorcode", {.fa = binlog_test_errorcode_main } },
	{ "test_filesystem", {.fa = binlog_test_filesystem_main } },
	{ "test_fundamentals", {.fa = binlog_test_fundamentals_main } },
	{ "test_optionals", {.fa = binlog_test_optionals_main } },
	{ "test_pointers", {.fa = binlog_test_pointers_main } },
	{ "test_strings", {.fa = binlog_test_strings_main } },
	{ "test_timepoint", {.fa = binlog_test_timepoint_main } },
	{ "test_tuples", {.fa = binlog_test_tuples_main } },
	{ "test_variants", {.fa = binlog_test_variants_main } },
	{ "test_named_writers", {.fa = binlog_test_named_writers_main } },
	{ "test_severity_control", {.fa = binlog_test_severity_control_main } },
	{ "test_shell", {.fa = binlog_test_shell_main } },

	{ "perf_large_log_file", {.fa = binlog_performance_large_log_file_main } },
	{ "perf_queue", { .fa = binlog_performance_queue_main } },
	{ "perf_session_writer", { .fa = binlog_performance_session_writer_main } },

#endif

MONOLITHIC_CMD_TABLE_END();

#include "monolithic_main_tpl.h"
