// O O O O O O O O O O O O O O O OO O OO O OO O O O TTCH O TTTCH O TTTCH O O O O
#pragma GCC optimize("Ofast")
// #pragma GCC optimize("no-stack-protector")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdio.h>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <random>
#include <iomanip>
#include <bitset>
#include <cassert>

using namespace std;

// #define int long long
#define double long double
#define less less228
#define left left228
#define right right228

template<typename T> void uin(T &a, T b) {
    if (b < a) a = b;
}
template<typename T> void uax(T &a, T b) {
    if (b > a) a = b;
}


random_device rnd;

template<typename T> void shuffle(vector< T > &v) {
    for (int i = 1; i < (int)v.size(); ++i) {
        swap(v[rnd() % i], v[i]);
    }
    for (int i = (int)v.size() - 1; i; --i) {
        swap(v[rnd() % i], v[i]);
    } 
}

const int N = 100 * 1000 + 228;

int a[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, l;
    cin >> n >> l;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] + a[i + 1] >= l) {
            cout << "Possible\n";
            for (int j = n - 1; j > i; --j) {
                cout << j << "\n";
            }
            for (int j = 1; j <= i; ++j) {
                cout << j << "\n";
            }
            return 0;
        }
    }
    cout << "Impossible\n";
    return 0;
}
// RU_023

/*
6 5 2
5 1 3 6 2 4
1 3
1 6
3 5
4 5
2 2

3 3 5
1 12 6
1 3
2 3
1 2

shironury

boootgslkfjdaojfdopsjfopjso
pgjq]pogjopsjg\qrwjopg
j
pogjqwrjgp]oqwjjqw]pjljfojpjowjow4jgopja    ohbip]aeo'rogpoaj0
[bkrw
pР С‘Р С—РЎС“РЎРѓРЎвЂљРЎРЉР В±РЎС“Р Т‘Р ВµРЎвЂљРЎР‚РЎС“Р С”Р В°РЎвЂљР Р†Р С•РЎРЏРЎвЂљР Р†Р ВµРЎР‚Р Т‘Р В°ojgqwjp\\j\;sync_with_stdiojp
ojeofmpworuc[owejgoprwig
[sdkz
pgj
p[gjes
p0ghjqsp[

jg
prsjgopjg]prwjgoprejgopjrepogjrepog]jgoprejgrgjporeqjgoperjgoprejgopeqrjgopeqrjgoprqwjgpoqjrwsopt4ng\ojsbjsoprnbfqsn\bvhqerpogjorwo
pwewh\rwh \wjiowe orw jop jgr\p jpj o jopj gr\pj p gjop j\pj\pe jp'oj [
 k
 p[eq   fj\pjfdwj\ejopjojopjopjf;'djpfsj, ipojs\p gpsdigsj gorkgjgjrogjdojgiao'fsdvopdshpdfidopcnweojccodj [cjd;ofjd[jdspmcojc"ajno[:Afvoq[w0shbprs`nm/jP{Vadmn;'fnc[Ajojsfpfjcffor 9int i= ; 1 < nfor (int i =1; for (int i =1 ; i <= n: ++i) frfor (int j = 1; j <= ml; ++'}]]]]]]]]]
5
1 5
1 2
2 3
2 
4
*/