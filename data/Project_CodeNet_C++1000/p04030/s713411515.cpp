#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n);i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

string s;

int main(){
    cin>>s;
    string ans="";

    rep(i,0,s.size()){
        if(ans!=""){
            if(s[i]=='0') ans=ans+"0";
            else if(s[i]=='1') ans=ans+"1";
            else ans.pop_back();
        }
        else{
            if(s[i]=='0') ans=ans+"0";
            else if(s[i]=='1') ans=ans+"1";           
        }
    }
    cout<<ans<<"\n";
    return 0;
}
