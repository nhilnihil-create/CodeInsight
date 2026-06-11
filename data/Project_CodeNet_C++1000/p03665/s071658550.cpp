#pragma region Macros
#include <bits/stdc++.h>
using namespace std;

// debug methods
// usage: debug(x,y);
#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0,a1,a2,a3,a4,x,...) x
#define debug_1(x1) cout<<#x1<<": "<<x1<<endl
#define debug_2(x1,x2) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<endl
#define debug_3(x1,x2,x3) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<endl
#define debug_4(x1,x2,x3,x4) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<endl
#define debug_5(x1,x2,x3,x4,x5) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<", "#x5<<": "<<x5<<endl
#ifdef LOCAL
    #define debug(...) CHOOSE((__VA_ARGS__,debug_5,debug_4,debug_3,debug_2,debug_1,~))(__VA_ARGS__)
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define debug(...) 42
    #define eprintf(...) 42
#endif

#define PI 3.1415926535897932384626433832795
#define INF 2e9
#define SINV(t) greater<t>()
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i, n) for(int i=(n); i>=0; --i)
#define FOR(i, n, m) for(int i=(m), i##_len=(n); i<i##_len; ++i)
#define FOREACH(i, v) for(const auto& i : v)
#define ALL(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;
#define vv(t) vector< t > 

#define CHC(mp, x) if(mp.end() != mp.find(x))
#define CHCV(mp, x) if(mp.end() != find(ALL(mp), x))

template<typename T>
inline T lcm(T a, T b) {return a / __gcd(a, b) * b;}

#pragma endregion

template<typename T>
void SV(vector<T> v){
    #ifdef LOCAL
        REP(i,v.size()){
                cout << i << " : " << v[i] << endl;
        }
    #endif
}

template<typename T>
void SV(map<int, T> v){
    #ifdef LOCAL
        FOREACH(i, v){
            cout << i.first << " : " << i.second << endl;
        }
    #endif
}
int bitCount(int bits) {
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    return (bits & 0x0000ffff) + (bits >> 16);
}

int main(void){
    int N, P;
    cin >> N >> P;
    int a=0, b=0;
    REP(i, N){
        int tmp;
        cin >> tmp;
        ((tmp%2)?a:b)++;
    }
    ll all=1ll<<N;
    ll m=1ll<<(a+b-1);
    if(a==0){
        m<<=1;
    }
    if(P){
        m=all-m;
    }
    debug(all);
    cout << m << endl;
    return 0;
}
