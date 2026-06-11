
/*
Problem

Category
全探索：ビット全探索
(参考: https://qiita.com/drken/items/7c6ff2aa4d8fce1c9361)

URL:
https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_b

考察:


Date: 2020/04/09
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

/* ==== declarations ====== */
// functions
void solve();
void getInput();

// global variables
int N, K;
vector<int> A;


/* ======================== */

signed main(){
    getInput();
    solve();
    return 0;
}

void getInput() {
    cin>>N>>K;
    A = vector<int>(N, 0);
    for(int i=0; i<N; ++i) {
        cin>>A[i];
    }
}

void solve() {
    int score = 10e16;
    for(int i=0; i< 1<<N; ++i) {
        // cout<<i<<"bitset: "<<bitset<16>(i)<<endl;
        int height = -1;
        int cnt = 0;
        int cost = 0;
        for(int j=0; j<N; ++j) {
            if (height < A[j]) {
                cnt++;
                height = A[j];
                continue;
            } else {
                bool canUp = (i & 1<<j);
                if (canUp) {
                    cost += height + 1 - A[j];
                    height++;
                    cnt++;
                }
            }
        }
        if (cnt >= K) {
            score = min(score, cost);
        }
        
    }
    cout<<score<<endl;
}




