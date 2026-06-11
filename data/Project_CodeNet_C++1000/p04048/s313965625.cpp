#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define rep(i,n) for(ll i=0;i<n;i++)
#define INF 1e9+7
#define LLINF 1e18
using namespace std;
const ll MOD = 1e9 +7;

ll gcd(ll a,ll b){
    if(b ==0) return a;
    return gcd(b,a%b);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll x,n;
    cin>>n>>x;
    cout<<3*(n-gcd(n,x))<<endl;
    return 0;
}
