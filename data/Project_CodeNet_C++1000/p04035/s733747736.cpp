#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int64_t i = 0; i < n; i++)
#define REPR(i, n) for(int64_t i = n; i >= 0; i--)
#define FOR(i, m, n) for(int64_t i = m; i < n; i++)
#define FORR(i, m, n) for(int64_t i = m; i >= n; i--)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    fill( (T*)array, (T*)(array+N), val );
}
template<class T>
inline bool chmax(T &a, T b) {if(a < b) {a = b;return true;}return false;}
template<class T>
inline bool chmin(T &a, T b) {if(a > b) {a = b;return true;}return false;}
const ll INF= 1ll << 60;
const ll MOD = 1000000007;
double EPS = 1e-10;
//----------------------------------------------------------

int N;
ll L;
ll a[100050];

int main(){
    cin >> N >> L;
    FOR(i,1,N+1)cin >> a[i];
    int cnt=-1;
    FOR(i,1,N)
    {
        if(a[i]+a[i+1]>=L){cnt=i;break;}
    }
    if(cnt==-1)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    FOR(i,1,cnt)
    {
        cout << i << endl;
    }
    FORR(i,N-1,cnt+1)
    {
        cout << i << endl;
    }
    cout << cnt << endl;
    return 0;
}