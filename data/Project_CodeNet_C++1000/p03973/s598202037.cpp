#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=a;i<n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

ll n,b,a,ans;

int main(){
    cin>>n>>b;
    ans=b-1;
    b=1;
    rep(i,n-1){
        cin>>a;
        if(a>b+1){
            ans+=(a-1)/(b+1);
            a=1;
        }
        b=max(a,b);
    }
    cout<<ans<<endl;
}