#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
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
    int A[N];
    rep(i,N) cin >> A[i];
    sort(A,A+N);
    if(A[N-1]-A[0]>1) cout << "No" << endl;
    else if(A[N-1]-A[0]==1){
        int lo=A[0];
        int cnt=0;
        rep(i,N) if(A[i]==lo) cnt++;
        if(cnt<=lo && lo+1<=cnt+(N-cnt)/2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else{
        if(A[0]<=N/2 ||A[0]==N-1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
