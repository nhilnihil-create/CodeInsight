#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1e9
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    ll n;
    cin>>n;
    ll t[n],a[n];
    for(int i=0;i<n;i++) cin>>t[i];
    for(int i=0;i<n;i++) cin>>a[i];
    ll ans=1;
    if(t[n-1]!=a[0]){
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<n-1;i++){
        if(t[i]==t[i-1] && a[i]==a[i+1]){
            ans*=min(t[i],a[i]);
            ans%=MOD;
        }
        else if(t[i]>t[i-1] && a[i]==a[i+1] && a[i]<t[i]) ans=0;
        else if(t[i]==t[i-1] && a[i]>a[i+1] && a[i]>t[i]) ans=0;
        else if(t[i]>t[i-1] && a[i]>a[i+1] && a[i]!=t[i]) ans=0;
    }
    
    cout<<ans<<endl;
}