#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF LLONG_MAX/10
#define rep(i,n) for(int i=0;i<n;i++)
#define krep(i,k,n,m) for(int i=k;i<n;i+=m)
#define erep(i,k,n) for(int i=k;i<n;i++)
#define mod 1000000007
//最大公約数
int gcd(int s,int b){
    if(b==0)return s;
    return gcd(b,s%b);
}
signed main(){
    int n,a,b;
    cin>>n>>a>>b;
    int x[n];
    rep(i,n){
        cin>>x[i];
    }
    int sa=b/a;
    int ans=0;
    rep(i,n-1){
        if(sa>=x[i+1]-x[i]){
            ans+=(x[i+1]-x[i])*a;
        }
        else{
            ans+=b;
        }
    }
    cout<<ans<<endl;
}
