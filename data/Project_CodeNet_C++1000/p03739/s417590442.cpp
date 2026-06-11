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

void func(long long n, std::vector<long long> a){

    lli ans = INF;

    lli cnt = 0;
    lli sum = 0;
    REP(i,0,n){
        sum+=a[i];
        if((i%2)==0){
            if(sum<=0){
                cnt += (abs(sum)+1);
                sum = 1;
            }
        }
        else{
            if(sum>=0){
                cnt += (abs(sum)+1);
                sum = -1;
            }
        }
    }
    chmin(ans,cnt);

    cnt=0;
    sum=0;
    REP(i,0,n){
        sum+=a[i];
        if((i%2)==0){
            if(sum>=0){
                cnt += (abs(sum)+1);
                sum = -1;
            }
        }
        else{
            if(sum<=0){
                cnt += (abs(sum)+1);
                sum = 1;
            }
        }
    }
    chmin(ans,cnt);
    cout<<ans<<endl;
}

int main(){
    // cout << fixed << setprecision(5);

    long long n;
    scanf("%lld",&n);
    std::vector<long long> a(n);
    for(int i = 0 ; i < n ; i++){
        scanf("%lld",&a[i]);
    }
    func(n, std::move(a));
    return 0;
}
