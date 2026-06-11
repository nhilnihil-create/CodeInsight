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

//r[k][i] 2^k経ったときにiから→に行ける箇所
lli r[63][100100];

void func(long long N, std::vector<long long> x, long long L, long long Q, std::vector<long long> a, std::vector<long long> b){

    x.push_back(INF);
    REP(i,0,N){
        auto itr = upper_bound(x.begin(),x.end(),x[i]+L);
        itr--;
        lli nexIndex = itr-x.begin();
        r[0][i] = nexIndex;
        LOG2(i,r[0][i]);
    }

    REP(k,1,62){
        REP(i,0,N){
            r[k][i] = r[k-1][r[k-1][i]];
            LOG3(k,i,r[k][i]);
        }
    }

    REP(i,0,Q){
        lli aa = a[i];
        lli bb = b[i];

        lli small = 0,large = 1e9;
        while(small+1<large){
            lli middle = small+large;
            middle/=2;

            lli now = aa;
            for(lli i=0;i<62;i++){
                if(middle&(1LL<<i))now = r[i][now];
            }

            if(now<bb)small=middle;
            else large = middle;
        }
        cout<<large<<endl;
    }



}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    std::vector<long long> x(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&x[i]);
    }
    long long L;
    scanf("%lld",&L);
    long long Q;
    scanf("%lld",&Q);
    std::vector<long long> a(Q);
    std::vector<long long> b(Q);
    for(int i = 0 ; i < Q ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
        a[i]--,b[i]--;
        if(a[i]>b[i])swap(a[i],b[i]);
    }
    func(N, std::move(x), L, Q, std::move(a), std::move(b));
    return 0;
}
