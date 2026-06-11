// ※※※ 解答不能 ※※※
// 正解者のソースを学習する.
// yutaka1999氏
// https://atcoder.jp/contests/agc008/submissions/1041743
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
    LL a, b, c, d, e, f, g;
    scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &g);
    LL ret = (a / 2) * 2LL + (d / 2) * 2LL + (e / 2) * 2LL;
    if(a >= 1 && d >= 1 && e >= 1) ret = max(ret, 3LL +((a - 1) / 2) * 2LL + ((d - 1) / 2) * 2LL + ((e - 1) / 2) * 2LL);
    printf("%lld\n", ret + b);
    return 0;
}