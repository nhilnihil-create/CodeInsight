/* 
 * Project: AtCoder Beginners Contest 072 A - Sandglass2
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/06/10
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
using namespace std;

int x, t;

void solve() {

    if (x > t) {
        printf("%d\n", x - t);
        return;
     } else {
        printf("%d\n", 0);
        return;
     }

}

int main() {

    scanf("%d", &x);
    scanf("%d", &t);

    solve();

}