#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
#define PI 3.141592653589
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << "No" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl

signed main(void){
    int N,M;
    int A[314][314];
    cin >> N >> M;
    REP(i,N){
        REP(j,M){
            cin >> A[i][j];
            A[i][j]--;
            A[i][j+1]=311;
        }
    }
    int Ans=N;
    bool E[314];
    int now[314]={};
    REP(j,M){
        //計測
        int F[314];
        REP(i,N){
            F[i]=A[i][now[i]];
        }
        
        //削除決定
        int G[314]={};
        REP(i,N){
            G[F[i]]++;
        }
        int h=0;
        REP(i,M){
            if(!E[i] && G[h]<G[i]){
                h=i;
            }
        }
        //削除
        //REP(i,N){cout << F[i] << " ";}cout << endl;cout << G[h] << endl;
        Ans=min(Ans,G[h]);
        E[h]=true;
        REP(i,N){
            while(1){
                if(E[A[i][now[i]]]==true){
                    now[i]++;
                }else{
                    break;
                }
            }
        }
    }
    cout << Ans << endl;
    
  return 0;
}

