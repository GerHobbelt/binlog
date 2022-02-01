
#pragma once

#if defined(BUILD_MONOLITHIC)

#ifdef __cplusplus
extern "C" {
#endif

	int binlog_bread_main(int argc, const char** argv);
	int binlog_brecovery_main(int argc, const char** argv);
	int binlog_example_consume_loop_main(int argc, const char** argv);
	int binlog_example_detailed_hello_main(int argc, const char** argv);
	int binlog_example_hello_main(int argc, const char** argv);
	int binlog_example_log_rotation_main(int argc, const char** argv);
	int binlog_example_multi_output_main(int argc, const char** argv);
	int binlog_example_text_output_main(int argc, const char** argv);
	int binlog_example_tsc_clock_main(int argc, const char** argv);
	int binlog_generate_foreach_main(int argc, const char** argv);

	int binlog_test_categories_main(int argc, const char** argv);
	int binlog_test_integration_main(int argc, const char** argv);
	int binlog_test_logging_main(int argc, const char** argv);
	int binlog_test_adapted_structs_main(int argc, const char** argv);
	int binlog_test_boost_types_main(int argc, const char** argv);
	int binlog_test_containers_main(int argc, const char** argv);
	int binlog_test_cstrings_main(int argc, const char** argv);
	int binlog_test_duration_main(int argc, const char** argv);
	int binlog_test_enums_main(int argc, const char** argv);
	int binlog_test_errorcode_main(int argc, const char** argv);
	int binlog_test_filesystem_main(int argc, const char** argv);
	int binlog_test_fundamentals_main(int argc, const char** argv);
	int binlog_test_optionals_main(int argc, const char** argv);
	int binlog_test_pointers_main(int argc, const char** argv);
	int binlog_test_strings_main(int argc, const char** argv);
	int binlog_test_timepoint_main(int argc, const char** argv);
	int binlog_test_tuples_main(int argc, const char** argv);
	int binlog_test_variants_main(int argc, const char** argv);
	int binlog_test_named_writers_main(int argc, const char** argv);
	int binlog_test_severity_control_main(int argc, const char** argv);
	int binlog_test_shell_main(int argc, const char** argv);

	int binlog_performance_large_log_file_main(int argc, const char** argv);
	int binlog_performance_queue_main(int argc, const char** argv);
	int binlog_performance_session_writer_main(int argc, const char** argv);

#ifdef __cplusplus
}
#endif

#endif
