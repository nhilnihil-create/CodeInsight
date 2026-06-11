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
#define GOODBYE cout << "-1" << endl;return 0
#define MM <<" "<<
#define Endl endl

int N;
int A[214514];
    
bool BSsolve(int S){
    int B[214514];
    int D[214514]={};
    int El[214514]={},Er[214514]={};
    REP(i,2*N-1){
        if(S<=A[i]){
            B[i]=1;
        }else{
            B[i]=0;
        }
    }
    //REP(i,2*N-1){cout << B[i] << " ";}cout<< " " << S;cout << endl;
    REP(i,2*N-3){
        if((B[i]-B[i+1])*(B[i+1]-B[i+2])==-1){
            D[i+1]=2;
        }
    }
    REP(i,2*N-1){
        if(D[i]==2){
            B[i]=2;
        }
    }
    REP(i,2*N-1){
        El[i]=i;
        Er[i]=i;
    }
    REP(i,2*N-1){
        if(i==0||i==2*N-2)continue;
        if(B[i]==2){
            El[i]=El[i-1];
        }
    }
    RREP(i,2*N-1){
        if(i==0||i==2*N-2)continue;
        if(B[i]==2){
            Er[i]=Er[i+1];
        }
    }
    REP(i,2*N-1){
        if(B[i]==2){
            if(abs(i-El[i])<abs(i-Er[i])){
                B[i]=B[El[i]];
            }else{
                B[i]=B[Er[i]];
            }
        }
    }
    
    //REP(i,2*N-1){cout << D[i] << " ";}cout << endl;
    //REP(i,2*N-1){cout << B[i] << " ";}cout << endl;
    return !!B[N-1];
}

int BinarySearch(int m,int M,int count){
    int L=min(m,M),R=max(m,M),mid;
    L--;
    while(abs(R-L)>1&&count>0){
        mid=(L+R)/2;
        if(BSsolve(mid)){
            L=mid;
        }else{
            R=mid;
        }
        count--;
    }
    return L;
}

signed main(){
    cin >> N;
    REP(i,2*N-1){
        cin >> A[i];
        A[i]--;
    }
    //REP(i,2*N-1){cout << A[i] << " ";}cout << endl;
    cout << BinarySearch(0,2*N-2,INF)+1 << endl;
    return 0;
}   
