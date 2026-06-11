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

void func(long long N, long long M, std::vector<std::vector<long long>> A){

    set<lli> s;
    REP(i,0,M)s.insert(i+1);

    lli ans = INF;

    while(s.size()){
        map<lli,lli> cnt;
        REP(i,0,N){
            REP(j,0,M){
                if(s.find(A[i][j]) != s.end()){
                    cnt[A[i][j]]++;
                    break;
                }
            }
        }
        lli maxSize=-1;
        lli maxIndex = -1;
        for(auto e:cnt){
            if(e.second > maxSize){
                maxSize = e.second;
                maxIndex = e.first;
            }
        }
        chmin(ans,maxSize);
        s.erase(maxIndex);
    }
    cout<<ans<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<std::vector<long long>> A(N, std::vector<long long>(M));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            scanf("%lld",&A[i][j]);
        }
    }
    func(N, M, std::move(A));
    return 0;
}
