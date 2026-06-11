#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

long long gcd(long long m,long long n){
    if(n==0){
        return m;
    }
    return gcd(n,m%n);
}
 
long long lcm(long long a,long long b){
    long long g=gcd(a,b);
    return a/g*b;
}
int main(){
    int n;
    cin>>n;
    vector<ll> t(n);

    rep(i,n) cin>>t[i];

    ll ans=t[0];
    for(int i=1;i<n;i++){
        ans=lcm(t[i],ans);
    }

    cout<<ans<<endl;
}