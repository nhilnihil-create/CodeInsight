#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
ll solve(vector <int> a){
    ll p0=0,p1=0;
    for (auto u : a){
        if (u%2==1) p1++;
        else p0++;
    }
    if (p0%2==1) return 1;
    if (p1!=1) return 0;
    for (int i=0;i<a.size();i++){
            if (a[i]%2==1)
                a[i]--;
            if (a[i]==0) return 0;
    }
    ll w=0;
    for (auto u : a) w=__gcd(w,u);
    for (int i=0;i<a.size();i++) a[i]/=w;
    return 1-solve(a);
}
int32_t main(){
    ll n;
    cin >> n;
    vector <int> a;
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        a.pb(x);
    }
    ll ans=solve(a);
    if (ans) kill("First");
    kill("Second");
}