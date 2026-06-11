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

lli boxNum[100100];
lli rNum[100100];

void func(long long N, long long M, std::vector<long long> x, std::vector<long long> y){

    REP(i,0,100100){
        boxNum[i]=1;
        rNum[i]=0;
    }
    rNum[0]=1;

    REP(i,0,M){
        boxNum[x[i]]--;
        boxNum[y[i]]++;
        if(rNum[x[i]]){
            rNum[y[i]]=1;
            if(boxNum[x[i]]==0)rNum[x[i]]=0;
        }
    }

    lli ans = 0;
    REP(i,0,N){
        if(rNum[i])ans++;
    }
    cout<<ans<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> x(M);
    std::vector<long long> y(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&x[i]);
        scanf("%lld",&y[i]);
        x[i]--;
        y[i]--;
    }
    func(N, M, std::move(x), std::move(y));
    return 0;
}
