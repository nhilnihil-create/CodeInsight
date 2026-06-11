#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
//#include <bits/stdc++.h>
using namespace std;

// rep (i, 回数) { // 0~回数-1
// 処理
//}
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main ()
{
    int k,s;
    cin >> k >> s;

    int count = 0 ;
    for( int x=0; x <=k; ++x){
        for( int y = 0; y<=k; ++y){
            const int zz = s-x-y;
            if( zz >=0  && zz <= k) {
                ++ count ;
            }
        }
    }


    cout << count;
    cout << endl;
    return 0;
}                       