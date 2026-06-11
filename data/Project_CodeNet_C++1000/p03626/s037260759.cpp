#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n;
string s,t;
ll ans[55];
ll M=1000000007;
int main(void){
    cin>>n;
    cin>>s>>t;
    if(s[0]==t[0]){
        ans[0]=3;
    }else{
        ans[1]=6;
    }
    for(int i=1;i<n;i++){
        if(ans[i]==0){
            if(s[i-1]==t[i-1]){
                if(s[i]==t[i]){
                    ans[i]=ans[i-1]*2%M;
                }else{
                    ans[i]=ans[i-1]*2%M;
                    ans[i+1]=ans[i];
                }
            }else{
                if(s[i]==t[i]){
                    ans[i]=ans[i-1];
                    //ans[i+1]=ans[i-1];
                }else{
                    ans[i]=ans[i-1]*3%M;
                    ans[i+1]=ans[i];
                }
            }
        }
        //cout<<ans[i]<<endl;
    }
    cout<<ans[n-1]<<endl;
    
}
