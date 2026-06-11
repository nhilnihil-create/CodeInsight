#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
#define all(v) v.begin(),v.end()
#define endl "\n"
#define clr(n, r) memset(n,r,sizeof(n));

void fast() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}


int main() {
    fast();
    ll n;cin>>n;
    ll x=0,y=0;
    while(n--){
        ll a,b;cin>>a>>b;
        ll l=1,r=1e18/max(a,b),mid,solu;
        while(l<=r){
            mid=(l+r)/2;
            if(mid*a>=x&&mid*b>=y)r=mid-1;
            else l=mid+1;
        }
        //cout<<solu<<" ";
        x=a*l;
        y=l*b;
       // cout<<x<<" "<<y<<" ";
    }
    cout<<x+y;
}