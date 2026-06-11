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



void func(long long a_I, long long a_O, long long a_T, long long a_J, long long a_L, long long a_S, long long a_Z){

    lli ans = 2*a_O;

    lli ijl = min({a_I,a_J,a_L});
    lli res = 0;

    if(ijl>0){
        res += 6+((a_I-1)/2)*4 + ((a_J-1)/2)*4 + ((a_L-1)/2)*4;
    }
    ans += max(res,(a_I/2)*4+(a_J/2)*4+(a_L/2)*4);

    cout<<ans/2<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    long long a_I;
    scanf("%lld",&a_I);
    long long a_O;
    scanf("%lld",&a_O);
    long long a_T;
    scanf("%lld",&a_T);
    long long a_J;
    scanf("%lld",&a_J);
    long long a_L;
    scanf("%lld",&a_L);
    long long a_S;
    scanf("%lld",&a_S);
    long long a_Z;
    scanf("%lld",&a_Z);
    func(a_I, a_O, a_T, a_J, a_L, a_S, a_Z);
    return 0;
}
