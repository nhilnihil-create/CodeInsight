/* 
 * Project: AtCoder Beginners Contest 069 B - i18n
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/06/04
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string s;

void solve() {
    
    printf("%c%d%c\n",s[0],(int)(s.size()-2),s[s.size()-1]);

}

int main() {

    cin >> s;

    solve();

}