#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a7=1000000007;
ll inf=1000000000000000;
typedef pair<ll,ll> l_l;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back


ll min(ll a,ll b){
    if(a<b)return a;
    return b;
}
ll max(ll a,ll b){
    if(a>b)return a;
    return b;
}

int main(){
    ll n;cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    ll dp[n];
    ll next=0;
    if(n==1){
        cout<<3<<endl;
        return 0;
    }else{
        if(s1[0]==s2[0]){
            dp[0]=3;
            next=1;
        }else{
            dp[1]=6;
            next=2;
        }
        while(next<n){
            if(s1[next]==s2[next]){
                if(s1[next-1]==s2[next-1]){
                    dp[next]=(dp[next-1]*2)%a7;
                }else{
                    dp[next]=dp[next-1];
                }
                next++;
            }else{
                if(s1[next-1]==s2[next-1]){
                    dp[next+1]=(dp[next-1]*2)%a7;
                }else{
                    dp[next+1]=(dp[next-1]*3)%a7;
                }
                
                next++;
                next++;
                
            }
            
            
        }
    }
    cout<<(dp[n-1])%a7<<endl;
    return 0;
}





