#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 100000000000000009
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define ZREP(i,n) for(int i=1;i<(n);++i)
#define YES(s) s?cout << "YES" << endl:cout << "NO" << endl
#define Yes(s) s?cout << "Yes" << endl:cout << "No" << endl
#define out(s,t,u) s?cout << t << endl:cout << u << endl
#define int ll
#define Endl endl


signed main(){
    int N;
    int A[300][300];
    cin >> N;
    REP(i,N){
        REP(j,N){
            cin >> A[i][j];
        }
    }
    
    REP(k,N){
        REP(i,N){
            REP(j,N){
                if(A[i][k]+A[k][j]<A[i][j]){
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }
    
    
    bool D[300][300]={};
    int Ans=0;
    
    REP(k,N){
        REP(i,N){
            REP(j,N){
                if(A[i][k]+A[k][j]==A[i][j] && A[i][k]>0 && A[k][j]>0){
                    D[i][j]=1;
                }
            }
        }
    }
    REP(j,N){
        REP(i,j){
            if(D[i][j]==0){
                Ans+=A[i][j];
            }
        }
    }
    
    cout << Ans << endl;
    return 0;
}
