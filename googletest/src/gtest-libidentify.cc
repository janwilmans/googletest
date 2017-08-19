// Copyright 2017, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Author: janwilmans@gmail.com (Jan Wilmans)
//

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "gtest-libidentify.h"

namespace LibIdentify {

void report(const std::string& description, const std::string& category, const std::string& framework, const std::string& version, int argc, char* argv[])
{
    for (int i = 0; i < argc; ++i)
    {
        std::string argument(argv[i]);
        if (argument == "--libidentify")
        {
            std::cout << std::left << std::setw(16) << "description: " << description << "\n";
            std::cout << std::left << std::setw(16) << "category: " << category << "\n";
            std::cout << std::left << std::setw(16) << "framework: " << framework << "\n";
            std::cout << std::left << std::setw(16) << "version: " << version << std::endl;
            exit(0);
        }
        
        if (argument == "--wait-for-keypress")
        {
            std::cout << "#waiting" << std::endl;
            std::getchar();
        }
    }   
}

void report(const std::string& version, int argc, char* argv[])
{
    report(framework_googletest, category_testframework, framework_googletest, version, argc, argv);
}

}