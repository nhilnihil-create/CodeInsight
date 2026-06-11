#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MIN(a) *min_element(all(a))
#define MAX(a) *max_element(all(a))
#define SUM(a, b) accumulate(all(a), b)
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define RREP(i, n) for(int (i)=(n)-1; (i)>=0; (i)--)
#define FOR(i, m, n) for(int (i)=(m); (i)<(n); i++)
#define FORR(i, m, n) for(int (i)=(n)-1; (i)>=(m); i--)
#define ios() cin.tie(0), ios::sync_with_stdio(false)
#define debug(x) cerr << #x << " = " << x << endl
//#define int long long

typedef long long ll;
typedef unsigned long long ull;
//ll const MOD = 998244353;
ll const MOD = 1e9+7;
ll const INF = 1e18;

template<typename T> int size(const T& a){return (int)a.size();}
template<typename T> T Div(T a, T b){return (a + b - 1) / b;}
template<typename T> bool chmin(T& a, const T& b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, const T& b){if(a < b){a = b; return true;} return false;}


bool f(int n, vector<bool>& v, vector<bool>& u){
    FOR(i, 2, n){
        u[i] = u[i-2] ^ u[i-1] ^ v[i-1];
    }
    if((u[n-1] ^ u[0] ^ u[1]) == v[0] && (u[n-2] ^ u[n-1] ^ u[0]) == v[n-1]){
        return true;
    }
    return false;
}

signed main(){
    int n;
    string s;
    cin >> n >> s;
    vector<bool> v(n);
    REP(i, n){
        v[i] = (s[i] == 'o' ? 0 : 1);
    }

    for(int i=0; i<=0b11; i++){
        vector<bool> u(n);
        u[0] = i & 1;
        u[1] = (i >> 1) & 1;
        if(f(n, v, u)){
            REP(i, n){
                cout << (u[i] ? 'W' : 'S');
            }
            cout << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    
    return 0;
}
