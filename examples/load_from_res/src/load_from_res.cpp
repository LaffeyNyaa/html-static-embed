/*
 * MIT License
 *
 * Copyright (c) 2025 LaffeyNyaa
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <inline_html.h>

#include <iostream>
#include <map>

#include "resource.h"

static const inline_html::resource_map RESOURCE_MAP = {
    {"index.html", IDR_HTML_INDEX},
    {"style.css", IDR_CSS_STYLE},
    {"script.js", IDR_JS_SCRIPT},
};

int main() {
    std::string html_data;

    try {
        html_data = inline_html::inline_html(IDR_HTML_INDEX, RESOURCE_MAP);
    } catch (const std::system_error &e) {
        std::cerr << e.code().message() << '\n';
        return 1;
    } catch (const std::out_of_range &e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    std::cout << html_data << '\n';

    return 0;
}