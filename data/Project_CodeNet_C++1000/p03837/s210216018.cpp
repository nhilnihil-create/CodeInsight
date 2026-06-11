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

lli dp[110][110];

void func(long long N, long long M, std::vector<long long> a, std::vector<long long> b, std::vector<long long> c){

    REP(k,0,N)REP(i,0,N)REP(j,0,N)chmin(dp[i][j],dp[i][k]+dp[k][j]);

    lli cnt = 0;
    REP(i,0,M){
        if(dp[a[i]][b[i]]!=c[i])cnt++;
    }

    cout<<cnt<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    REP(i,0,110)REP(j,0,110)dp[i][j]=INF;
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> a(M);
    std::vector<long long> b(M);
    std::vector<long long> c(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
        scanf("%lld",&c[i]);
        a[i]--,b[i]--;
        dp[a[i]][b[i]]=c[i];
        dp[b[i]][a[i]]=c[i];
    }
    func(N, M, std::move(a), std::move(b), std::move(c));
    return 0;
}
