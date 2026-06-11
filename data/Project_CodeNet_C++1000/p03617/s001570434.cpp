#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int INF=1e9;

ll gcd(ll x,ll y){
    if(y==0) return 0;
    return gcd(y,x%y);
}

int main(){
    ll a[4];
    for(int i=0;i<4;i++) cin>>a[i];
    a[0]*=4;a[1]*=2;
    ll n;cin>>n;
    ll ans=min(*min_element(a,a+3)*n,a[3]*(n/2)+*min_element(a,a+3)*(n%2));
    cout<<ans<<endl;
    return 0;
}