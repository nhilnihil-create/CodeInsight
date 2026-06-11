#pragma region
#pragma GCC target("avx2")
#pragma GCC optimize("03")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std; typedef long double ld; typedef long long ll;
typedef unsigned long long ull;
#define endl "\n"
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORR(x,arr) for(auto& x:arr)
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define VPII vector<PII>
#define VPLL vector<PLL>
#define FI first 
#define SE second
#define ALL(x) (x).begin(), (x).end()
constexpr int INF=1<<30; constexpr ll LINF=1LL<<60; constexpr ll mod=1e9+7; constexpr int NIL = -1;
template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
#pragma endregion
//-------------------
float sug[3005];

int main(){
    cin.tie(0); ios::sync_with_stdio(false); //cout << fixed << setprecision(15);
    float a,b,c,d,e,f; cin >> a >> b >> c >> d >> e >> f;
    float noudo = 0;

    float ans_wat;
    float ans_sug;
    
    FOR(i,1,3000) {
        sug[i] = sug[i-1];
        if(i-c>=0) chmax(sug[i], sug[i-(int)c]+c);
        if(i-d>=0) chmax(sug[i], sug[i-(int)d]+d);
    }
    FOR(i,0,30) {
        FOR(j,0,30) {
            float wat = i*a*100 + j*b*100;
            if(wat >= f) continue;
            float can = sug[(int)(wat/100 * e)]; 
            if(can > f - wat) can = f-wat;
            if(noudo <= can/(wat+can)) {
                // cout << wat << " " << can << endl;
                noudo = can/(wat+can);
                ans_wat = wat;
                ans_sug = can;
            }
        }
    }
    cout << (int)(ans_wat+ans_sug) << " " << (int)ans_sug << endl;
    return 0;
}
