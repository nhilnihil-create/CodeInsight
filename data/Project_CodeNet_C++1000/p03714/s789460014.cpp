#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include <cassert>
#include <cmath>
#include<cstdint>

#define INF 1e9
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

string dp[20000];

int main(){
    int n;
    cin >> n;
    VEC(ll, a, 3 * n);

    vector<ll>pre(n + 1, 0), suf(n + 1, 0);

    priority_queue<ll, vector<ll>, greater<ll>> pq_M;
    rep(i, n){
        pq_M.push(a[i]);
        pre[0] += a[i];
    }
    
    int now = 0;
    REP(i, n, 2 * n - 1){
        now++;
        ll MIN = pq_M.top();
        if(MIN < a[i]){
            pre[now] = pre[now - 1] - MIN + a[i];
            pq_M.pop();
            pq_M.push(a[i]);
        }
        else pre[now] = pre[now - 1];
    }




    priority_queue<ll> pq_m;
    reverse(ALL(a));
    rep(i, n){
        pq_m.push(a[i]);
        suf[0] += a[i];
    }

    now = 0;
    REP(i, n, 2 * n - 1){
        now++;
        ll MAX = pq_m.top();
        if(MAX > a[i]){
            suf[now] = suf[now - 1] - MAX + a[i];
            pq_m.pop();
            pq_m.push(a[i]);
        }
        else suf[now] = suf[now - 1];
    }

    reverse(ALL(suf));
    
    ll res = -INF * INF;
    const int len = pre.size();
    rep(i, len){
        res = max(res, pre[i] - suf[i]);
    }
    cout << res << endl;
}

