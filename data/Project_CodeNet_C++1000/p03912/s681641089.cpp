#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int N, M;
vector<int> X;

void input(void){
    cin >> N >> M;
    X.resize(N);
    for (auto& xi : X)
        cin >> xi;
}

map<int, map<int, int>> mod_M_cnt;
map<int, int> cnt;

void build(void){
    for (auto xi : X)
        ++mod_M_cnt[xi % M][xi], ++cnt[xi % M];
}

int main(void){
    input();
    build();
    int res = 0;
    res += cnt[0] / 2;
    if (M % 2 == 0)
        res += cnt[M / 2] / 2;
    for (int i = 1; i <= M / 2; ++i){
        if (i == M - i) continue;
        res += min(cnt[i], cnt[M - i]);
        if (cnt[i] < cnt[M - i]){
            swap(cnt[i], cnt[M - i]);
            swap(mod_M_cnt[i], mod_M_cnt[M - i]);
        }    
        int tmp = 0;
        for (auto e : mod_M_cnt[i])
            tmp += e.second / 2;
        res += min((cnt[i] - cnt[M - i]) / 2, tmp);
    }
    cout << res << endl;
    return 0;
}