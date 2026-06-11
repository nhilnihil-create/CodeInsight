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

signed main(void){
    int N,K;
    int A[114514],B[114514];
    cin >> N >> K;
    REP(i,N){
        cin >> A[i] >> B[i];
    }
    int L=K;
    int Ans=0;
    int e=0;
    while(1){
        int num=0;
        REP(i,N){
            if((L|A[i])==L){
                num+=B[i];
            }
        }
        if(L<=K){
            Ans=max(Ans,num);
        }
        
        //cout << L MM num<< endl;
        L|=(1<<e);
        L&= ~(1<<(e+1));
        e++;
        
        if(L>=2*K)break;
    }
    cout << Ans << endl;
    return 0;
}

