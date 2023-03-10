#!/bin/bash

set -e

cmake -S . -B build/coverage -G Ninja -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTING=ON -DQCOLORPICKER_REPORT_COVERAGE=ON $@
cmake --build build/coverage -j
ctest --test-dir build/coverage --output-on-failure -j
llvm-profdata merge -sparse build/coverage/test/default.profraw -o coverage.profdata
llvm-cov show build/coverage/test/qcolorpicker_test_ui --instr-profile=coverage.profdata --ignore-filename-regex=build/ --format=html -o coverage_report
rm build/coverage/test/qcolorpicker_filter_history
rm -fr coverage.profdata
