#pragma GCC optimize ("O3")
/*
    Prodigia comploratus,
    silens, oro:
    "Regnet exitium."
*/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using db = long double;
const int N = 1e5 + 5, MOD = 1e9 + 7;
/*
    for every i i need to maintain somethings
    the number of ranges such that l < i <= r
    the sum of distances between r and i
    the first one can be done easily using some kind of line sweep
*/
vector<pair<int,int>> ranges;
int n, m, a[N];
int num[N];
ll sum[N];
ll sumOut[N];
void calcNum(){
    vector<int> evs(m + 1);
    vector<vector<int>> add(m + 1), rem(m+1);
    int cur = 0;
    ll curSUM = 0;
    ll curOut = 0;
    for(auto x : ranges){
        if(x.first > x.second)
            curOut += x.first + m - x.second;
        else{
            curOut += x.second - x.first;
        }
    }
    for(auto x : ranges){
        if(x.first > x.second){
            cur++;
            curOut -= x.first + m - x.second;
            curSUM += x.second - 1;
        }
        evs[x.first]++;
        evs[x.second]--;
        add[x.first].push_back(x.second);
        rem[x.second].push_back(x.first);
    }
    for(int i = 1; i <= m; i++){
        num[i] = cur;
        sum[i] = curSUM;
        sumOut[i] = curOut;
        cur += evs[i];
        for(auto to : add[i]){
            if(to > i)curSUM += to-i, curOut -= (to - i);
            else curSUM += to + m - i, curOut -= (to + m - i);
        }
        for(auto to : rem[i]){
//            cout << i << ' ' << to << '\n';
            if(to < i)curOut += i - to;
            else curOut += i + m - to;
        }
//        cout << curOut << ' ' << rem[to] << '\n';
        curSUM -= cur;
    }
}
int main(){

    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++){
        scanf("%d", a + i);
        if(i > 1)
            ranges.emplace_back(a[i-1], a[i]);
    }

    calcNum();
    ll out = LLONG_MAX;
    for(int i = 1; i <= m; i++){
//        cout << num[i] << ' ' << sumOut[i] << ' ' << sum[i] << '\n';
        out = min(out,  sumOut[i] + num[i] + sum[i]);
    }
    cout << out << '\n';
    return 0;
}
