#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
ll GCD(ll a,ll b){
    if(b==0) return a;
    return GCD(b,a%b);
}
int main() {
    int n;
    cin>>n;
    vector<ll> a(n);
    ll lcm,gcd;
    rep(i,n){
        cin>>a[i];
        if(i==0) lcm=a[i];
        else{
            gcd=GCD(lcm,a[i]);
            lcm=(lcm/gcd)*a[i];
        }
    }
    cout<<lcm;
}