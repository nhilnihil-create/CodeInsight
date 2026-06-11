#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;
#define pb push_back
#define fi first
#define se second
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
template <class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p){os<<"("<<p.first<<","<< p.second<<")";return os;}
template <class T> ostream &operator<<(ostream &os, const vector<T> &v){os<<"{";REP(i,(int)v.size()){if(i)os<<",";os<<v[i];}os<<"}";return os;}
template <typename T, size_t S> void printArray(const T (&array)[S]){for(auto val : array)std::cout << val << ", ";std::cout << "\n";}
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}
const double PI=acos(-1);
const ll MOD = 1000000007;
using Graph = vector<vector<int>>;
template<class T>inline bool chmax(T& a, T b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T& a, T b){if(a > b){a = b; return 1;}return 0;}
const ll INF = 1LL<<60;
//const int dy[4] = {0, 1, 0, -1};
//const int dx[4] = {1, 0, -1, 0};
//const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
//const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};

void solve(){
    string s; cin >> s;
    vector<ll> a(4, 0); //a[0]:N, a[1]:S, a[2]:E, a[3]:W
    REP(i, s.size()){
        if(s[i] == 'N') a[0]++;
        if(s[i] == 'S') a[1]++;
        if(s[i] == 'E') a[2]++;
        if(s[i] == 'W') a[3]++;
    }
    if(a[0] > 0 && a[1] > 0 && a[2] == 0 && a[3] == 0 || a[0] == 0 && a[1] == 0 && a[2] > 0 && a[3] > 0 || a[0] > 0 && a[1] > 0 && a[2] > 0 && a[3] > 0) Yes();
    else No();
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}