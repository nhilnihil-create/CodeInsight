#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << "{" <<p.first << ", " << p.second << "}";
  return os;
}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N;
    cin >> N;
    vector<int> p(N);
    rep(i,N){
        cin >> p[i];
        p[i]--;
    }
    ll d = 20000 + 1;
    vector<ll> a(N),b(N);
    a[0] = 1;
    rep(i,N-1)a[i+1] = a[i] + d;
    b.back() = 1;
    int start = 0;
    rep(i,N){
        if(p[i] == N - 1)start = i;
    }
    for(int i = start; i+1 < N; i++){
        ll y = p[i];
        ll x = p[i+1];
        ll delta_a = abs(a[y] - a[x]);
        if(x < y){
            b[x] = b[y] + delta_a + 1;
        }
        else{
            b[x] = b[y] - delta_a + 1;
        }
    }
    for(int i = start; i - 1 >= 0; i--){
        ll y = p[i-1];
        ll x = p[i];
        ll delta_a = abs(a[x] - a[y]);
        if(x < y){
            b[y] = b[x] - delta_a - 1;
        }
        else{
            b[y] = b[x] + delta_a - 1;
        }
    }
    // print(p);
    // print(a);
    // print(b);
    rep(i,N){
        cout << a[i] << " ";
    }
    cout << endl;
    rep(i,N){
        cout << b[i] << " ";
    }
    cout << endl;
    // rep(i,N){
    //     cerr << a[i] + b[i] << " ";
    // }
    // cout << endl;
}
