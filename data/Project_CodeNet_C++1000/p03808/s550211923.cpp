//
//  ROIGold.cpp
//  Main calisma
//
//  Created by Rakhman on 05/02/2019.
//  Copyright © 2019 Rakhman. All rights reserved.
//

#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iterator>
#include<unordered_map>

#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define S second
#define F first
#define pb push_back
#define nl '\n'
#define NL cout << '\n';
#define EX exit(0)
#define all(s) s.begin(), s.end()
#define FOR(i, start, finish, k) for(llong i = start; i <= finish; i += k)

const long long MXN = 1e6 + 100;
const long long MNN = 4444;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long long OO = 1e9 + 1;
const double pi = acos(-1.0);

typedef long long llong;
typedef unsigned long long ullong;

using namespace std;

llong n, b[MXN], sum, mx;

int main(){
    ios;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        sum += b[i];
        mx = max(b[i], mx);
    }
    llong x = n * (n + 1) / 2;
    if(sum % x != 0){
        cout << "NO";
        return 0;
    }
    int k = sum / x;
    for(int i = 1; i < n; i++){
        llong d = b[i + 1] - b[i];
        if(k - d >= 0 && (k - d) % n == 0){
            continue;
        }else{
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
/*
 
1 1 - 1
2 1 - 1
3 1 - 1
4 1 - 1
5 1 - 1
6 1 - 1
7 1 - 1
 
1 2 - 0
2 2 - 1
3 2 - 2
4 2 - 3
5 2 - 4
6 2 - 5
7 2 - 6
 
1 3 - 1
2 3 - 1
3 3 - 1
4 3 - 3
5 3 - 6
6 3 - 10
7 3 - 15
8 3 - 21
9 3 - 28
10 3 - 36
 
1 4 - 1
2 4 - 1
3 4 - 1
4 4 - 1
5 4 - 4
6 4 - 10
7 4 - 20
8 4 - 35
9 4 - 56
10 4 - 84

1 5 - 1
2 5 - 1
3 5 - 1
4 5 - 1
5 5 - 1
5 5 - 1
6 5 - 5
7 5 - 15
8 5 - 35
9 5 - 70
10 5 - 126
*/
