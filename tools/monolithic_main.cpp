
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifdef _MSC_VER
#include <io.h>
#else
#include <unistd.h>
#endif
#include <errno.h>

#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest/doctest.h>

#define BUILD_MONOLITHIC 1
#include "monolithic_examples.h"


typedef int tool_f();
typedef int tool_fa(int argc, const char** argv);

static int usage();


static struct cmd_info
{
	const char* cmd;
	union
	{
		tool_f* f;
		tool_fa* fa;
	} f;
} commands[] = {

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

	{ "?", {.f = usage } },
	{ "h", {.f = usage } },
	{ "help", {.f = usage } },
	{ "-?", {.f = usage } },
	{ "-h", {.f = usage } },
	{ "--help", {.f = usage } },
};


static void help(void)
{
	fprintf(stderr, "Commands:\n");
	for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++)
	{
		struct cmd_info el = commands[i];
		fprintf(stderr, "  %s\n", el.cmd);
	}
}


static int usage()
{
#if defined(BUILDING_BINLOG_TOOLS)
	fprintf(stderr, "Usage: binlog_tools [command]\n");
#else
	fprintf(stderr, "Usage: binlog_tests [command]\n");
#endif
	help();
	return 1;
}


static int parse(const char* source, int argc, const char** argv)
{
	if (source)
	{
		for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++)
		{
			struct cmd_info el = commands[i];
			size_t cmd_len = strlen(el.cmd);
			char sentinel = 0;

			if (strlen(source) >= cmd_len)
				sentinel = source[cmd_len];

			if (strncmp(source, el.cmd, cmd_len) == 0 && (sentinel == 0 || isspace(sentinel)))
			{
				return el.f.fa(argc, argv);
			}
		}

		fprintf(stderr, "Unknown command '%s'.\n\nUse 'h' or 'help' command to get a list of supported commands.\n", source);
		return 1;
	}
	else
	{
		return usage();
	}
}

int main(int argc, const char** argv)
{
	return parse(argv[1], argc - 1, argv + 1);
}

