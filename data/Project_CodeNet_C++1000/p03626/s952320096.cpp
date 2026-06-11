#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(4);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
constexpr int MOD=1000000007;
//constexpr int MOD=998244353;
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

int main(void){
    int N;
    cin >> N;
    char S[2][N];
    bool used[N]={};
    rep(i,2) cin >> S[i];
    lint ans=1;
    rep(i,N){
        if(S[0][i]==S[1][i]){
            if(i==0) ans=ans*3;
            else if(S[0][i-1]!=S[1][i-1]) ans*=1;
            else ans=(ans*2)%MOD;
        }
        if(S[0][i]!=S[1][i]){
            if(i>0) if(used[i-1]) continue;
            if(i==0) ans=ans*6;
            else if(S[0][i-1]!=S[1][i-1]) ans=(ans*3)%MOD;
            else ans=(ans*2)%MOD;
            used[i]=true;
        }
    }
    cout << ans << endl;
}