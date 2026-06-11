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
    int N;
    int A[114514];
    cin >> N;
    REP(i,N){
        cin >> A[i];
    }
    int M=-INF,m=INF;
    REP(i,N){
        M=max(M,A[i]);
        m=min(m,A[i]);
    }
    if(M-m>=2){GOODBYE;}
    
    if(M==m){
        if(2*m<=N){
            cout << "Yes" << endl;
            return 0;
        }
        if(m==N-1){
            cout << "Yes" << endl;
            return 0;
        }
        GOODBYE;
    }
    
    //M-m=1
    int mnum=0;
    REP(i,N){
        if(A[i]==m){
            mnum++;
        }
    }
    
    if(mnum<=m && 2*(M-mnum)<=(N-mnum)){
        cout << "Yes" << endl;
        return 0;
    }
    GOODBYE;
    
    
  return 0;
}

