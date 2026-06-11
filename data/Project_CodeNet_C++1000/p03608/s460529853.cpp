#include <bits/stdc++.h>
using namespace std;
 
#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define TO_STRING(VariableName) # VariableName
#define LOG(x) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<endl;
#define LOG2(x,y) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<endl;
#define LOG3(x,y,z) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<" "<<TO_STRING(z)<<"="<<z<<endl;
#define LOG4(w,x,y,z) if(DEBUG)cout<<TO_STRING(w)<<"="<<w<<" "<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<" "<<TO_STRING(z)<<"="<<z<<endl;
 
template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
 
lli d[300][300];
 
void func(long long N, long long M, long long R, std::vector<long long> r, std::vector<long long> A, std::vector<long long> B, std::vector<long long> C){
 
    vector<lli> per(R);
    REP(i,0,R)per[i]=i;
 
    REP(k,0,N)REP(i,0,N)REP(j,0,N)chmin(d[i][j],d[i][k]+d[k][j]);
 
    lli ans = INF;
 
    do{
        lli sum = 0;
        REP(i,1,R){
            sum += d[r[per[i-1]]][r[per[i]]];
        }
        chmin(ans,sum);
 
    }while(next_permutation(per.begin(),per.end()));
 
    cout<<ans<<endl;
 
}
 
int main(){
    // cout << fixed << setprecision(5);
    REP(i,0,300)REP(j,0,300)d[i][j]=INF;
    REP(i,0,300)d[i][i]=0;
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    long long R;
    scanf("%lld",&R);
    std::vector<long long> r(R);
    for(int i = 0 ; i < R ; i++){
        scanf("%lld",&r[i]);
        r[i]--;
    }
    std::vector<long long> A(M);
    std::vector<long long> B(M);
    std::vector<long long> C(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&A[i]);
        scanf("%lld",&B[i]);
        scanf("%lld",&C[i]);
        A[i]--,B[i]--;
        d[A[i]][B[i]]=C[i];
        d[B[i]][A[i]]=C[i];
    }
    func(N, M, R, std::move(r), std::move(A), std::move(B), std::move(C));
    return 0;
}