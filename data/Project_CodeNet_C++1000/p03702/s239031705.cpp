#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue> 
#include <stack>
#include <set>
#include <list>

using namespace std;
typedef long long ll;
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define all(x) x.begin(),x.end()


int main()
{
    ll n,a,b;cin>>n>>a>>b;
    ll c=a-b;
    vector<ll> h(n);rep(i,n)cin>>h[i];
    ll ng=0,ok=1e9;
    while(abs(ok-ng)>1){
        ll mid=(ok+ng)/2;
        ll cnt=0;
        rep(i,n){
            ll d=mid*b;
            ll r=max(0LL,h[i]-d);
            cnt+=(r+c-1)/c;
        }
        if(cnt<=mid)ok=mid;
        else ng=mid;
    }
    cout<<ok<<endl;
}