#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
//#define INF 810114514
#define PI 3.141592653589
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
#define debug false


signed main(void){
    int N,M,R;
    int a;
    vector<int> r,A,B,C;
    
    cin >> N >> M >> R;
    REP(i,R){cin >> a;a--;r.push_back(a);}
    REP(i,M){
        cin >> a;a--;
        A.push_back(a);
        cin >> a;a--;
        B.push_back(a);
        cin >> a;
        C.push_back(a);
    }
    sort(r.begin(),r.end());
    
    int dp[205][205];
    REP(i,205){
        REP(j,205){
            dp[i][j]=INF;
        }
        dp[i][i]=0;
    }
    
    REP(i,M){
        dp[A[i]][B[i]]=C[i];
        dp[B[i]][A[i]]=C[i];
    }
    
    REP(k,N){
        REP(i,N){
            REP(j,N){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    
    int Ans=INF;
    do{
        int num =0;
        REP(i,R-1){
            num+=dp[r[i]][r[i+1]];
        }
        Ans=min(Ans,num);
        /*REP(i,R){
            cout << r[i] << " "; 
        }cout << "  ";
        cout << num << endl;*/
    }while(next_permutation(r.begin(),r.end()));
    
    cout << Ans << endl;
    return 0;
}

