#include<iostream>
#include<iomanip>
#include<cstdio>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}

/*
クエリN<=K<=2N を試す

Kまでの大きいほうからN個の和、K以降の小さいほうからN個の和を取りたい



*/

int main() {

    int N; cin >> N;
    vector<int> a(3*N);
    for (int i = 0; i < 3 * N; i++) cin >> a[i];
    vector<ll> S1(N+1,0), S2(N+1,0);

    ll s1 = 0, s2 = 0;
    priority_queue<int> que;
    priority_queue<int, vector<int>, greater<int> > QUE;
    for (int i = 0; i < N; i++) {
        s1 += a[i]; QUE.push(a[i]);
        s2 += a[3*N-i-1]; que.push(a[3*N-i-1]);
    }
    S1[0] = s1; S2[N] = s2;
    for (int i = 0; i < N; i++) {
        s1 += a[i+N]; QUE.push(a[i+N]);
        s1 -= QUE.top(); QUE.pop();
        S1[i+1] = s1;
    }
    for (int i = N-1; i >= 0; i--) {
        s2 += a[i+N]; que.push(a[i+N]);
        s2 -= que.top(); que.pop();
        S2[i] = s2;
    }
    ll res = -1e18;
    for (int i = 0; i <= N; i++) {
        chmax(res,S1[i] - S2[i]);
    }
    cout << res << endl;








}
