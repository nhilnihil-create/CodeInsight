#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a-1; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<ll>> v;
vector<ll> cost;



int main(){
    ll h, w;    cin >> h >> w;
    vector<vector<char>> g(h, vector<char>(w, '0'));
    map<char, ll> key;
    rep(i, h) rep(j, w){
        char c; cin >> c;
        key[c] += 1;
    }
    
    ll c2=0, c4=0, odd=0;
    for(auto x: key){
        if(x.second%4==0) c4++;
        else if(x.second%4==2)   c2++;
        else odd++;
    }
    string res="Yes";
    if(h*w%2) odd -= 1;
    if(h%2) c2 -= w/2;
    if(w%2) c2 -= h/2;
    if(0<odd || 0<c2) res = "No";
    
    cout << res << endl;
       
}
