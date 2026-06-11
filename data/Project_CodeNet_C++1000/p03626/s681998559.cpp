#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define rep(i,n) for(int i=0;i<n;i++)
#define mod 1000000007 // 10^9+7
#define INF 99999999999 //10^12-1
#define dev 998244353 //tenka1
#define P pair<int,int>
#define F first
#define S second
int n,start;
int ans=1;
bool b=true;
string s,t;
signed main(){
    cin>>n>>s>>t;
    if(s[0]==t[0]){
        start=1;
        ans*=3;
    }
    else{
        start=2;
        ans*=6;
    }
    for(int i=start;i<n;i++){
        if(s[i-1]==t[i-1])ans*=2;
        else if(s[i]!=t[i])ans*=3;
        if(s[i]!=t[i])i++;
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}



