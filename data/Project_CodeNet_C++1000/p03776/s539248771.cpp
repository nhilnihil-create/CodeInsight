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

const lli MAX = 1000100;
const lli MOD = 1000000007;

lli dp[100][100];

void func(long long N, long long A, long long B, std::vector<long long> v){

    A--,B--;
    sort(v.rbegin(),v.rend());

    dp[0][0]=1;
    REP(i,0,100){
        REP(j,0,i+1){
            dp[i+1][j] += dp[i][j];
            dp[i+1][j+1] += dp[i][j];
        }
    }

    map<lli,lli> cnt;
    REP(i,0,N)cnt[v[i]]++;
    
    lli ans = 0;
    double ansper=0;
    cout<<setprecision(15);
    if(v[0]==v[A]){
        lli s = A+1;
        lli e = min(B+1,cnt[v[0]]);
        REP(i,s,e+1){
            ans += dp[cnt[v[0]]][i];
        }
        ansper = v[0];
    }
    else{
        REP(i,0,A+1)ansper += v[i];
        lli length = 0;
        REP(i,0,N)if(v[i]>v[A])length++;
        ansper = ansper/(double)(A+1);
        ans = dp[cnt[v[A]]][A-length+1];
        LOG2(A,length)
    }
    cout<<ansper<<endl;
    cout<<ans<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    std::vector<long long> v(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&v[i]);
    }
    func(N, A, B, std::move(v));
    return 0;
}
