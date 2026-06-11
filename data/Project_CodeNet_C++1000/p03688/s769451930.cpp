#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MIN(a) *min_element(all(a))
#define MAX(a) *max_element(all(a))
#define SUM(a) accumulate(all(a), 0LL)
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define RREP(i, n) for(int (i)=(n)-1; (i)>=0; (i)--)
#define FOR(i, m, n) for(int (i)=(m); (i)<(n); i++)
#define FORR(i, m, n) for(int (i)=(n)-1; (i)>=(m); i--)
#define debug(x) cerr << #x << " = " << x << endl
//#define int long long

typedef long long ll;
//ll const MOD = 998244353;
ll const MOD = 1e9+7;
int const inf = 1e9;
ll const INF = 1e18;

inline void ios_(){cin.tie(0); ios::sync_with_stdio(false);}
template<typename T> int size(const T& a){return (int)a.size();}
template<typename T> T Div(T a, T b){return (a + b - 1) / b;}
template<typename T> bool chmin(T& a, const T& b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, const T& b){if(a < b){a = b; return true;} return false;}



signed main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto&& i : v) cin >> i;

    sort(all(v));
    if(v[n-1]- v[0] > 1) {
        cout << "No" << endl;
        return 0;
    }

    if(v[n-1] == v[0]) {
        cout << (v[0] == n-1 || n / v[0] >= 2 ? "Yes" : "No") << endl;
        return 0;
    }

    int s = 0, l = 0;
    REP(i, n){
        if(v[i] == v[0]){
            s++;
        }else{
            l++;
        }
    }

    if(l == 1){
        cout << "No" << endl;
        return 0;
    }

    if(s + 1 <= v[n-1] && s + l / 2 >= v[n-1]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
