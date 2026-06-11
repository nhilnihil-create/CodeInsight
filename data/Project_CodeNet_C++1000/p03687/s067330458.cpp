#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstdio>
#include<cmath>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
int MOD=1000000007;
int inf=1e18;
bool judge(string const& s,char x){
    int n=s.length();
    rep(i,n){
        if(s[i]!=x){
            return false;
        }
    }
    return true;
}
string pro(string const& s,char x){
    int n=s.length();
    string res;
    rep(i,n-1){
        if(s[i+1]==x){
            res+=x;
        }
        else{
            res+=s[i];
        }
    }
    return res;
}
signed main(){
    string s;cin>>s;
    int res=inf;
    rep(i,26){
        string buf=s;
        int cnt=0;
        while(!judge(buf,'a'+i)){
            buf=pro(buf,'a'+i);
            cnt++;
            if(cnt>105)break;
        }
        res=min(res,cnt);
    }
    cout<<res<<"\n";
    return 0;
}