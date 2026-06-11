/* 
 * Project: AtCoder Beginners Contest 051 A - Haiku
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/06/14
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
using namespace std;

char s[19];

void solve() {
    for (int i=0;i<19;i++) {
        if (s[i] == ',')
            printf(" ");
        else
            printf("%c", s[i]);
    }
    printf("\n");

}

int main() {

    scanf("%s", s);

    solve();

}