#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ll n,k;
    cin>>n>>k;
    vector<ll> num(100010);
    ll a,b;
    rep(i,n){
        cin>>a>>b;
        num[a-1]+=b;
    }
    ll sum=0;
    rep(i,100000){
        sum+=num[i];
        if(sum>=k){
            cout<<i+1;
            return 0;
        }
    }
}