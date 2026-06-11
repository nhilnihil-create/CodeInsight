/* 
 * Project: AtCoder Beginners Contest 053 
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/06/11
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstring>
using namespace std;

char s[200000];

void solve() {
    
    int cnt_a = 0;
    int cnt_z = 0;
    bool is_find_a = false;
    bool is_find_z = false;
    for (int i=0;i<strlen(s)-1;i++) {
        if (is_find_a) {
            ;
        } else if (!strncmp(&s[i], "A", 1)) {
            cnt_a = i;
            is_find_a = true;
        }
        if (is_find_z) {
            ;
        } else if (!strncmp(&s[strlen(s)-1-i], "Z", 1)) {
            cnt_z = i;
            is_find_z = true;
        }
    }
    printf("%ld\n", strlen(s)-cnt_z-cnt_a);
}

int main() {

    scanf("%s", s);

    solve();

}