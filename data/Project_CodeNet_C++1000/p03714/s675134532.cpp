#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n; cin >> n;
    vector<int> a(n*3);
    rep(i,3*n) cin >> a[i];
    vector<ll> s(n*2+1, 0);//左i個中から大きいn個の和
    priority_queue<ll, vector<ll>, greater<ll>> left;
    rep(i,n){
        s[i+1] = s[i] + a[i];
        left.push(a[i]);
    }
    for(int i =n; i < 2*n; ++i){
        ll mi = left.top();
        if(a[i] > mi){
            s[i+1] = s[i] - mi + a[i];
            left.pop();
            left.push(a[i]);
        }else s[i+1] = s[i];
    }
    vector<ll> t(2*n+1);//右i個中から小さいn個の和
    priority_queue<ll> right;
    rep(i,n){
        t[i+1] = t[i] + a[n*3 - 1 - i];
        right.push(a[n*3-1 - i]);
    }
    for(int i = n; i < 2*n; ++i){
        ll ma = right.top();
        if(a[n*3-1 - i] < ma){
            t[i+1] = t[i] - ma + a[n*3-1 - i];
            right.pop();
            right.push(a[n*3-1 - i]);
        }else t[i+1] = t[i];
    }
    ll ans = -(1LL << 60);
    for(int i = n; i <= 2*n; ++i){
        ans = max(ans, s[i] - t[n*3 - i]);
    }
    cout << ans << endl;
}