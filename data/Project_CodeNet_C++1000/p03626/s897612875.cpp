#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int main(){
    int n;
    string s,t;
    cin>>n>>s>>t;
    ll ans=1;
    bool prev=false;
    for(int i=0;i<n;i++){
        if(i!=n-1&&s[i]==s[i+1]){
            if(prev)ans=(ans*3)%MOD;
            else ans=(ans*2)%MOD;
            if(i==0)ans=6;
            prev=1;
            i++;
        }
        else{
            if(!prev)ans=(ans*2)%MOD;
            if(i==0)ans=3;
            prev=0;
        }
    }
    cout<<ans<<endl;
}
