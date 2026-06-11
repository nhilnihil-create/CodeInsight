#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define V vector<ll>
#define A for(auto &x:a)cin>>x;
#define B for(auto &x:b)cin>>x;
#define C for(auto &x:c)cin>>x;
#define Q int tt,qq; cin>>tt ;for(qq=1;qq<=tt;qq++)
#define I ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int main()
{
    ll n,i,j,ans=1;
    cin>>n;
    map<ll,ll>m;
    for(i=0;i<n;i++){
        cin>>j;
        m[j]++;
    }
    if(n%2==0){
        for(i=1;i<n;i+=2)if(m[i]!=2){i=-1;break;}
        if(i==-1)ans=0;
        else{
            for(i=0;i<n/2;i++){
                ans*=2;
                ans%=(ll)1e9+7;
            }
        }
    }
    else{
        for(i=2;i<n;i+=2)if(m[i]!=2){i=-1;break;}
        if(m[0]!=1)i=-1;
        if(i==-1)ans=0;
        else{
            for(i=0;i<n/2;i++){
                ans*=2;
                ans%=(ll)1e9+7;
            }
        }
    }
 //   for(auto x:m)cout<<x.first<<" "<<x.second<<endl;
    cout<<ans;
}
