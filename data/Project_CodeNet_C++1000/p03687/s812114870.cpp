#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
constexpr int MOD=1000000007;
#define INF (1<<30)
#define LINF (lint)(1LL<<56)
#define endl "\n"
#define rep(i,n) for(lint (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(lint (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcount(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
#define fi first
#define se second
typedef long long lint;
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
const int MAX_N=2e5+5;

bool only(string S){
    bool res=true;
    rep(i,S.size()-1) if(S[i]!=S[i+1]) res=false;
    return res;
}

int main(void){
    string S;
    cin >> S;
    int N=S.length();
    int ans=INF;
    int alf[26]={};
    rep(i,N) alf[S[i]-'a']++;
    rep(i,26){
        if(alf[i]==0) continue;
        char c='a'+i;
        string s=S;
        int cnt=0;
        while(!only(s)){
            string nw;
            rep(j,s.size()-1){
                if(s[j]==c || s[j+1]==c) nw+=c;
                else nw+='0';
            }
            cnt++;
            s=nw;
        }
        ans=min(ans,cnt);
    }
    cout << ans << endl;
}