#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    ll n,m;
    cin>>n>>m;
    if(2*n>=m) cout<<min(n,m/2)<<endl;
    else cout<<n+(m-2*n)/4<<endl;
    return 0;
}