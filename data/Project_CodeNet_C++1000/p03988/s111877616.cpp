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
#define GOODBYE do { cout << "Impossible" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl

signed main(void){
    int N;
    int a;
    vector<int> A;
    int B[114]={};
    cin >> N;
    REP(i,N){
        cin >> a;
        A.push_back(a);
        B[a]++;
    }
    sort(A.begin(),A.end());
    int K=A[N-1];
    if(B[K]<2)GOODBYE;
    for(int i=K;i>(K+1)/2;i--){
        B[i]-=2;
        if(B[i]<0)GOODBYE;
    }
    B[(K+1)/2]--;if(K%2==1){B[(K+1)/2]--;}
    if(B[(K+1)/2]<0)GOODBYE;
    
    REP(i,N){
        if(i<=(K+1)/2 && B[i]>0)GOODBYE;
    }
    
    cout << "Possible" << endl;
    
    return 0;
}

