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


const string YES = "YES";
const string NO = "NO";

void func(long long N, std::vector<long long> A){

    lli oneAct = (N+1)*N/2;
    vector<lli> b(N);
    lli sum = 0;
    REP(i,0,N){
        sum += A[i];
        b[i] = A[(i+1)%N] - A[i];
    }

    if(sum%oneAct != 0){
        cout<<NO<<endl;
        return;
    }

    lli cnt = 0;
    lli target = sum/oneAct;

    REP(i,0,N){
        LOG3(i,b[i],N);
        if((target-b[i])<0 || (target-b[i])%N != 0){
            cout<<NO<<endl;
            return;
        }
        cnt += (target-b[i])/N;
    }

    if(cnt != target){
        cout<<NO<<endl;
        return;
    }
    cout<<YES<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    func(N, std::move(A));
    return 0;
}
