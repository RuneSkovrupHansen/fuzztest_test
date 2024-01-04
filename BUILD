cc_test(
    name = "first_fuzz_test",
    srcs = ["src/first_fuzz_test.cc"],
    deps = [
        "@com_google_fuzztest//fuzztest",
        "@com_google_fuzztest//fuzztest:fuzztest_gtest_main",
        "@com_google_googletest//:gtest"
    ],
)

cc_test(
    name = "test_character",
    srcs = [
        "src/test_character.cpp",
    ],
    deps = [
        ":character",
        "@com_google_fuzztest//fuzztest",
        "@com_google_fuzztest//fuzztest:googletest_fixture_adapter",
        "@com_google_fuzztest//fuzztest:fuzztest_gtest_main",
        "@com_google_googletest//:gtest"
    ],
)

cc_library(
    name = "character",
    srcs = [
        "src/character.cpp",
    ],
    hdrs = [
        "include/character.hpp",
    ],
    includes = [
        "include/",
    ],
    visibility = ["//visibility:public"],
)

