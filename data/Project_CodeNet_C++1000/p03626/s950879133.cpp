#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
int main(void){
    int n;
    string s[2];
    cin>>n>>s[0]>>s[1];
    ll ans;
    int i=1;
    bool tate=true;
    if(s[0][0]==s[1][0]) ans=3;
    else{
        ans=6;
        i=2;
        tate=false;
    }
    for(;i<n;){
        if(tate){
            if(s[0][i]==s[1][i]){
                ans=(ans*2)%mod;
                tate=true;
                i++;
            }
            else{
                ans=(ans*2)%mod;
                tate=false;
                i+=2;
            }
        }
        else{
            if(s[0][i]==s[1][i]){
                tate=true;
                i++;
            }
            else{
                ans=(ans*3)%mod;
                i+=2;
            }
        }
    }
    cout<<ans<<endl;
}