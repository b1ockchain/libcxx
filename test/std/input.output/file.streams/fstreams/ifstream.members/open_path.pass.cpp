//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++03, c++11, c++14
// UNSUPPORTED: libcpp-has-no-filesystem-library

// Filesystem is supported on Apple platforms starting with macosx10.15.
// UNSUPPORTED: use_system_cxx_lib && x86_64-apple-macosx10.14
// UNSUPPORTED: use_system_cxx_lib && x86_64-apple-macosx10.13
// UNSUPPORTED: use_system_cxx_lib && x86_64-apple-macosx10.12
// UNSUPPORTED: use_system_cxx_lib && x86_64-apple-macosx10.11
// UNSUPPORTED: use_system_cxx_lib && x86_64-apple-macosx10.10
// UNSUPPORTED: use_system_cxx_lib && x86_64-apple-macosx10.9

// FILE_DEPENDENCIES: test.dat

// <fstream>

// template <class charT, class traits = char_traits<charT> >
// class basic_ifstream

// void open(const filesystem::path& s, ios_base::openmode mode = ios_base::in);

#include <fstream>
#include <filesystem>
#include <cassert>

#include "test_macros.h"

int main(int, char**) {
  {
    std::ifstream fs;
    assert(!fs.is_open());
    char c = 'a';
    fs >> c;
    assert(fs.fail());
    assert(c == 'a');
    fs.open(std::filesystem::path("test.dat"));
    assert(fs.is_open());
    fs >> c;
    assert(c == 'r');
  }
  {
    std::wifstream fs;
    assert(!fs.is_open());
    wchar_t c = L'a';
    fs >> c;
    assert(fs.fail());
    assert(c == L'a');
    fs.open(std::filesystem::path("test.dat"));
    assert(fs.is_open());
    fs >> c;
    assert(c == L'r');
  }

  return 0;
}
