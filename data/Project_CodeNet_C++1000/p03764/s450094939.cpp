#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define ZREP(i,n) for(int i=1;i<(n);++i)
#define int ll
#define Endl endl

signed main(){
    int N,M;
    int A[114514],B[114514];
    int X=0,Y=0;
    cin >> N >> M;
    REP(i,N){cin >> A[i];}
    REP(i,M){cin >> B[i];}
    REP(i,N-1){
        X=(X+(i+1)*(N-i-1)*(A[i+1]-A[i]))%MOD;
    }
    REP(i,M-1){
        Y=(Y+(i+1)*(M-i-1)*(B[i+1]-B[i]))%MOD;
    }
    cout << (X*Y)%MOD << endl;
    return 0;
}
