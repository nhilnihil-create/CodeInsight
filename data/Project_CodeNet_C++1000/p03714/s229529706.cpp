#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
using namespace std;
#define r(i,n) for(int i=0;i<n;i++)
#define ll long long
const ll mod = 1000000007;


int main(){
    int N;
    cin >> N;
    vector<ll> a(3*N, 0);
    for (int i = 0; i < 3*N; i++) scanf("%lld", &a[i]);

    vector<ll> lsum(3*N, 0);
    priority_queue<ll, vector<ll>, greater<ll> > q;
    for (int i = 0; i < N; i++) {
        lsum[N-1] += a[i];
        q.push(a[i]);
    }
    for (int i = N; i < 2*N; i++) {
        lsum[i] = lsum[i-1] + a[i];
        q.push(a[i]);
        lsum[i] -= q.top();
        q.pop();
    }

    vector<ll> rsum(3*N, 0);
    priority_queue<ll> r;
    for (int i = 3*N-1; i >= 2*N; i--) {
        rsum[2*N] += a[i];
        r.push(a[i]);
    }
    for (int i = 2*N-1; i >= N; i--) {
        rsum[i] = rsum[i+1] + a[i];
        r.push(a[i]);
        rsum[i] -= r.top();
        r.pop();
    }
    ll ans = lsum[N-1]-rsum[N];
    for (int i = N; i < 2*N; i++) {
        if (lsum[i] - rsum[i+1] > ans) ans = lsum[i] - rsum[i+1];
    }
    cout << ans << endl;
    return 0;
}
