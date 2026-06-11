#include <bits/stdc++.h>
using namespace std;
//#define MOD 1000000007
#define MOD 998244353
#define INF 1145141919810893364
//#define INF 810MEM
//#define PI 3.141592653589
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << "0" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl

 
signed main(void){
    int N,M,Q;
    const int MEM=114514;
    int A[MEM],B[MEM];
    int v[MEM],d[MEM],c[MEM];
    cin >> N >> M;
    REP(i,M){
        cin >> A[i] >> B[i];
        A[i]--;B[i]--;
    }
    cin >> Q;
    REP(i,Q){
        cin >> v[i] >> d[i] >> c[i];
        v[i]--;
    }
    
    vector<int> G[MEM];
    REP(i,M){
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }
    
    int dp[MEM][11]={};
    REP(i,MEM){
        REP(j,11){
            dp[i][j]=-1;
        }
    }
    REP(i,Q){
        dp[v[i]][d[i]]=i;
    }
    RREP(j,11){
        if(j==0)continue;
        REP(i,N){
            REP(k,G[i].size()){
                dp[G[i][k]][j-1]=max(dp[G[i][k]][j-1],dp[i][j]);
            }
        }
    }
    
    /*
    REP(i,11){
        REP(j,N){
            //cout << (dp[j][i]!=0?c[dp[j][i]-1]:0) << " ";
            cout << dp[j][i] << " ";
        }cout << endl;
    }cout << endl;*/
    
    REP(i,N){
        int mx=-INF;
        REP(j,11){
            mx=max(mx,dp[i][j]);
        }
        if(mx<0){
            cout << 0 << endl;
        }else{
            cout << c[mx] << endl;
        }
    }
    
    return 0;
}

