#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll long long
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
//typedef vector<unsigned int>vec;
typedef vector<ll>vec;
typedef vector<vec> mat;
typedef vector<vector<int>> Graph;

//const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
//const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const ll  MOD = 1000000007;
//const ll MOD = 998244353;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> a(N);
    int mi = INF, ma = 0;
    REP(i,N){
        cin >> a[i];
        chmax(ma,a[i]);
        chmin(mi,a[i]);
    }
    if(ma == mi){
        if(ma == N - 1 || 2*ma <= N) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else if(ma - mi == 1){
        int x = count(a.begin(), a.end(), mi);
        int y = count(a.begin(), a.end(), ma);
        if(x < ma && 2*(ma-x) <= y) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else cout << "No" << endl;

}