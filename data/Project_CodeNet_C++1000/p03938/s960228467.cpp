#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define srep(i,l,n) for(int i = l; i < (int)(n); i++)
#define drep(i,n) for(int i = (int)(n-1); i >= 0; i--)
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
void Yes(){cout << "Yes" << endl;}
void No(){cout << "No" << endl;}
void YES(){cout << "YES" << endl;}
void NO(){cout << "NO" << endl;}
void err() {cout << -1 << endl;}
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back

const int MOD = 1000000007;
const int INF = 1e9;

#define PI acos(-1);
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};


int main(){
    int n;
    cin >> n;
    vector<int> pos(n);
    rep(i, n) cin >> pos[i], pos[i]--;
    vector<int> a(n), b(n);
    rep(i, n) a[i] = i+1, b[i] = n-i;
    vector<int> adda(n, 0), addb(n, 0);
    rep(i, n) {
        adda[pos[i]] += i;
        addb[pos[i]] += i;
    }
    rep(i, n-1) {
        adda[i+1] = adda[i] + adda[i+1];
    }
    drep(i, n-1) {
        addb[i] = addb[i+1] + addb[i];
    }
    rep(i, n) cout << a[i]+adda[i] << " ";
    cout << endl;
    rep(i, n) cout << b[i]+addb[i] << " ";
    cout << endl;
}