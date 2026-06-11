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
    string s;
    cin>>s;
    int k=INF;
    int ans=0,con=0,kai=0;
    for(int i=97;i<=122;i++){
        ans=0;
        con=0;
        kai=0;
        rep(j,s.size()){
            if(s[j]==i){
                ans=max(ans,con);
                con=0;
                kai++;
            }
            else{
                con++;
            }
        }
        ans=max(ans,con);
        k=min(k,ans);
    }
    cout<<k<<endl;
}
