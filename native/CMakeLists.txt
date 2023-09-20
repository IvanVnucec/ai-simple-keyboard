# Sets the minimum version of CMake required to build the native
# library. You should either keep the default value or only pass a
# value of 3.4.0 or lower.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds it for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        jni_latinime

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        # Associated headers in the same location as their source
        # file are automatically included.
        dicttoolkit/dict_toolkit_main.cpp;
        dicttoolkit/src/command_executors/diff_executor.cpp;
        dicttoolkit/src/command_executors/header_executor.cpp;
        dicttoolkit/src/command_executors/help_executor.cpp;
        dicttoolkit/src/command_executors/info_executor.cpp;
        dicttoolkit/src/command_executors/makedict_executor.cpp;
        dicttoolkit/src/offdevice_intermediate_dict/offdevice_intermediate_dict.cpp;
        dicttoolkit/src/utils/arguments_parser.cpp;
        dicttoolkit/src/utils/command_utils.cpp;
        dicttoolkit/src/utils/utf8_utils.cpp;
        jni/io_github_ctrlaltdel_aosp_ime_keyboard_ProximityInfo.cpp;
        jni/io_github_ctrlaltdel_aosp_ime_latin_BinaryDictionary.cpp;
        jni/io_github_ctrlaltdel_aosp_ime_latin_BinaryDictionaryUtils.cpp;
        jni/io_github_ctrlaltdel_aosp_ime_latin_DicTraverseSession.cpp;
        jni/jni_common.cpp;
        jni/src/dictionary/header/header_policy.cpp;
        jni/src/dictionary/header/header_read_write_utils.cpp;
        jni/src/dictionary/property/ngram_context.cpp;
        jni/src/dictionary/structure/backward/v402/bigram/ver4_bigram_list_policy.cpp;
        jni/src/dictionary/structure/backward/v402/content/bigram_dict_content.cpp;
        jni/src/dictionary/structure/backward/v402/content/probability_dict_content.cpp;
        jni/src/dictionary/structure/backward/v402/content/shortcut_dict_content.cpp;
        jni/src/dictionary/structure/backward/v402/content/sparse_table_dict_content.cpp;
        jni/src/dictionary/structure/backward/v402/content/terminal_position_lookup_table.cpp;
        jni/src/dictionary/structure/backward/v402/ver4_dict_buffers.cpp;
        jni/src/dictionary/structure/backward/v402/ver4_dict_constants.cpp;
        jni/src/dictionary/structure/backward/v402/ver4_patricia_trie_node_reader.cpp;
        jni/src/dictionary/structure/backward/v402/ver4_patricia_trie_node_writer.cpp;
        jni/src/dictionary/structure/backward/v402/ver4_patricia_trie_policy.cpp;
        jni/src/dictionary/structure/backward/v402/ver4_patricia_trie_reading_utils.cpp;
        jni/src/dictionary/structure/backward/v402/ver4_patricia_trie_writing_helper.cpp;
        jni/src/dictionary/structure/backward/v402/ver4_pt_node_array_reader.cpp;
        jni/src/dictionary/structure/dictionary_structure_with_buffer_policy_factory.cpp;
        jni/src/dictionary/structure/pt_common/bigram/bigram_list_read_write_utils.cpp;
        jni/src/dictionary/structure/pt_common/dynamic_pt_gc_event_listeners.cpp;
        jni/src/dictionary/structure/pt_common/dynamic_pt_reading_helper.cpp;
        jni/src/dictionary/structure/pt_common/dynamic_pt_reading_utils.cpp;
        jni/src/dictionary/structure/pt_common/dynamic_pt_updating_helper.cpp;
        jni/src/dictionary/structure/pt_common/dynamic_pt_writing_utils.cpp;
        jni/src/dictionary/structure/pt_common/patricia_trie_reading_utils.cpp;
        jni/src/dictionary/structure/pt_common/shortcut/shortcut_list_reading_utils.cpp;
        jni/src/dictionary/structure/v2/patricia_trie_policy.cpp;
        jni/src/dictionary/structure/v2/ver2_patricia_trie_node_reader.cpp;
        jni/src/dictionary/structure/v2/ver2_pt_node_array_reader.cpp;
        jni/src/dictionary/structure/v4/content/dynamic_language_model_probability_utils.cpp;
        jni/src/dictionary/structure/v4/content/language_model_dict_content.cpp;
        jni/src/dictionary/structure/v4/content/language_model_dict_content_global_counters.cpp;
        jni/src/dictionary/structure/v4/content/shortcut_dict_content.cpp;
        jni/src/dictionary/structure/v4/content/sparse_table_dict_content.cpp;
        jni/src/dictionary/structure/v4/content/terminal_position_lookup_table.cpp;
        jni/src/dictionary/structure/v4/ver4_dict_buffers.cpp;
        jni/src/dictionary/structure/v4/ver4_dict_constants.cpp;
        jni/src/dictionary/structure/v4/ver4_patricia_trie_node_reader.cpp;
        jni/src/dictionary/structure/v4/ver4_patricia_trie_node_writer.cpp;
        jni/src/dictionary/structure/v4/ver4_patricia_trie_policy.cpp;
        jni/src/dictionary/structure/v4/ver4_patricia_trie_reading_utils.cpp;
        jni/src/dictionary/structure/v4/ver4_patricia_trie_writing_helper.cpp;
        jni/src/dictionary/structure/v4/ver4_pt_node_array_reader.cpp;
        jni/src/dictionary/utils/buffer_with_extendable_buffer.cpp;
        jni/src/dictionary/utils/byte_array_utils.cpp;
        jni/src/dictionary/utils/dict_file_writing_utils.cpp;
        jni/src/dictionary/utils/file_utils.cpp;
        jni/src/dictionary/utils/forgetting_curve_utils.cpp;
        jni/src/dictionary/utils/format_utils.cpp;
        jni/src/dictionary/utils/mmapped_buffer.cpp;
        jni/src/dictionary/utils/multi_bigram_map.cpp;
        jni/src/dictionary/utils/probability_utils.cpp;
        jni/src/dictionary/utils/sparse_table.cpp;
        jni/src/dictionary/utils/trie_map.cpp;
        jni/src/suggest/core/dicnode/dic_node.cpp;
        jni/src/suggest/core/dicnode/dic_node_utils.cpp;
        jni/src/suggest/core/dicnode/dic_nodes_cache.cpp;
        jni/src/suggest/core/dictionary/dictionary.cpp;
        jni/src/suggest/core/dictionary/dictionary_utils.cpp;
        jni/src/suggest/core/dictionary/digraph_utils.cpp;
        jni/src/suggest/core/dictionary/error_type_utils.cpp;
        jni/src/suggest/core/layout/additional_proximity_chars.cpp;
        jni/src/suggest/core/layout/proximity_info.cpp;
        jni/src/suggest/core/layout/proximity_info_params.cpp;
        jni/src/suggest/core/layout/proximity_info_state.cpp;
        jni/src/suggest/core/layout/proximity_info_state_utils.cpp;
        jni/src/suggest/core/policy/weighting.cpp;
        jni/src/suggest/core/result/suggestion_results.cpp;
        jni/src/suggest/core/result/suggestions_output_utils.cpp;
        jni/src/suggest/core/session/dic_traverse_session.cpp;
        jni/src/suggest/core/suggest.cpp;
        jni/src/suggest/policyimpl/gesture/gesture_suggest_policy_factory.cpp;
        jni/src/suggest/policyimpl/typing/scoring_params.cpp;
        jni/src/suggest/policyimpl/typing/typing_scoring.cpp;
        jni/src/suggest/policyimpl/typing/typing_suggest_policy.cpp;
        jni/src/suggest/policyimpl/typing/typing_traversal.cpp;
        jni/src/suggest/policyimpl/typing/typing_weighting.cpp;
        jni/src/utils/autocorrection_threshold_utils.cpp;
        jni/src/utils/char_utils.cpp;
        jni/src/utils/jni_data_utils.cpp;
        jni/src/utils/log_utils.cpp;
        jni/src/utils/time_keeper.cpp)

# Specifies a path to native header files.
include_directories(dicttoolkit/src/command_executors/;
        dicttoolkit/src/;
        dicttoolkit/src/offdevice_intermediate_dict/;
        dicttoolkit/src/utils/;
        jni/;
        jni/src/;
        jni/src/dictionary/header/;
        jni/src/dictionary/interface/;
        jni/src/dictionary/property/;
        jni/src/dictionary/structure/backward/v402/bigram/;
        jni/src/dictionary/structure/backward/v402/content/;
        jni/src/dictionary/structure/backward/v402/shortcut/;
        jni/src/dictionary/structure/backward/v402/;
        jni/src/dictionary/structure/;
        jni/src/dictionary/structure/pt_common/bigram/;
        jni/src/dictionary/structure/pt_common/;
        jni/src/dictionary/structure/pt_common/shortcut/;
        jni/src/dictionary/structure/v2/bigram/;
        jni/src/dictionary/structure/v2/;
        jni/src/dictionary/structure/v2/shortcut/;
        jni/src/dictionary/structure/v4/content/;
        jni/src/dictionary/structure/v4/shortcut/;
        jni/src/dictionary/structure/v4/;
        jni/src/dictionary/utils/;
        jni/src/suggest/core/dicnode/;
        jni/src/suggest/core/dicnode/internal/;
        jni/src/suggest/core/dictionary/;
        jni/src/suggest/core/layout/;
        jni/src/suggest/core/policy/;
        jni/src/suggest/core/result/;
        jni/src/suggest/core/;
        jni/src/suggest/policyimpl/gesture/;
        jni/src/suggest/policyimpl/typing/;
        jni/src/suggest/policyimpl/utils/;
        jni/src/utils/)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because system libraries are included in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in the
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        jni_latinime

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib} )