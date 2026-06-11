#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
 
ll MOD = 1000000007;
ll INF =1<<29;
 
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    rep (i,n) a[i]++;
    vector<int> b(n),c(n);
    rep(i,n){
        b[i]=a[i]-1;
        c[i]=a[i]+1;
    }
    vector<int> cnt(100100);
    rep(i,n){
        cnt[a[i]]++;
        cnt[b[i]]++;
        cnt[c[i]]++;
    }
    int ans =0;
    rep(i,100100){
        ans = max(ans,cnt[i]);
    }
    cout << ans <<endl;
}