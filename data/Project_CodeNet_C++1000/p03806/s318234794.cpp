#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector> 
#include<limits>
#include<numeric>
#include<type_traits>
#include<math.h>
#include<fstream>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7; 

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define out(str) cout << str << endl
#define ALL(a) (a).begin(),(a).end()
#define INF_INT (1<<30)
#define INF_LL (1ll<<62)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int N,Ma,Mb,dp[50][500][500];

int main(){
    cin>>N>>Ma>>Mb;
    int a[N],b[N],c[N];
    rep(i,50){
        rep(j,500){
            rep(k,500){
                dp[i][j][k]=10000;
            }
        }
    }
    dp[0][0][0]=0;
    rep(i,N){
        cin>>a[i]>>b[i]>>c[i];
    }
    rep(i,N){
        rep(j,500){
            rep(k,500){
                dp[i+1][j][k] = min(dp[i+1][j][k],dp[i][j][k]);
                dp[i+1][a[i]+j][b[i]+k] = min(dp[i][j][k] + c[i], dp[i][a[i]+j][b[i]+k]);
            }
        }
    }

    int ans=10000000;
    repi(i,1,500)ans=min(dp[N][Ma*i][Mb*i],ans);
    if(ans<10000)out(ans);
    else out(-1);
    
    
}