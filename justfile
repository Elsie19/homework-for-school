clang-flags := "-O3 -march=native -pipe -Wall -Werror"

default: _create-output-dir hello-world exact-decimals approx-decimals

clean:
    @rm -rf out/*

format:
    @clang-format -i **/*.cpp

_create-output-dir:
    @mkdir -p out/

hello-world:
    clang++ {{clang-flags}} 01-hello-world/hello.cpp -o out/01-hello-world

exact-decimals:
    clang++ {{clang-flags}} 02-exact-decimals/exact-decimal.cpp -o out/02-exact-decimals

approx-decimals:
    clang++ {{clang-flags}} 03-approx-decimals/approx.cpp -o out/03-approx-decimals
