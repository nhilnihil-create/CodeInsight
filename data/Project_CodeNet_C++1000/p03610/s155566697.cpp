/* 
 * Project: AtCoder Beginners Contest 072 B - OddString
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/06/10
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstring>
using namespace std;

char s[100000];

void solve() {
    
    int length = strlen(s);
    for (int i=0;i<length;i+=2) {
        printf("%c", s[i]);
    }
    printf("\n");

}

int main() {

    scanf("%s", s);

    solve();

}