//
//  Median Pyramid Hard.cpp
//  National Olympiad in Informatics in Provinces
//
//  Created by 黄子齐 on 2019/10/5.
//  Copyright © 2019 黄子齐. All rights reserved.
//

#include <stdio.h>
const int N = 2e5+10;
int a[N], n;
bool b[N];
inline bool check(int mid) {
    for (int i=1; i<=2*n-1; i++) {
        b[i] = (!(a[i]<=mid));
    }
    for (int l=n-1, r=n+1; l>=1; l--, r++) {
        if (b[l] == b[l+1]) {
            return b[l];
        } else if (b[r] == b[r-1]) {
            return b[r];
        }
    }
    return b[1];
}
int main() {
//    freopen("mytestdata.in", "r", stdin);
    scanf("%d", &n);
    for (int i=1; i<=2*n-1; i++) {
        scanf("%d", &a[i]);
    }
    int l=1, r=2*n-1;
    while (l < r) {
        int mid=l+r>>1;
        if (check(mid)) {
            l = mid+1;
        } else {
            r = mid;
        }
    }
    printf("%d\n", l);
    return 0;
}
