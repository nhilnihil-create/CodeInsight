#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;

const ll mod=1e9+7;

int main(){
    ll n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    ll ans=1;
    bool flag=0;
    rep(i,n){
        if(s1[i]==s2[i]){
            if(i==0) ans*=3;
            else if(flag==0) ans*=2;
            flag=0;
        }else{
            if(i==0) ans*=6;
            else if(flag==0) ans*=2;
            else ans*=3;
            flag=1;
            i++;
        }
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}