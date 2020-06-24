# !/bin/bash

cd build
./ds_gtest
lcov -d CMakeFiles/ds_gtest.dir/gtest -t ds_gtest -o 'ds_gtest.cov.info' -b . -c
genhtml -o cov_result ds_gtest.cov.info
tar -zcvf cov_result.tgz cov_result
cp cov_result.tgz ..
cd -
