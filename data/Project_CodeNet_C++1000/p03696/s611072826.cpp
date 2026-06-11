#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define P pair<ll, ll>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define pp pair<ll, pair<ll, ll>> 
#define fi first
#define se second

void print(Vl vec){
    rep(i, 0, sz(vec)){
        if(i) cout << " ";
        cout << vec[i];
    }
    coel;
}

////////////////////////////////////////////////////////


int main() {
    ll n; cin >> n;
    string s; cin >> s;
    ll cnt = 0;
    ll a = 0, b = 0;
    rep(i, 0, n){
        if(s[i]=='(') cnt++;
        else{
            if(cnt==0) a++;
            else cnt--;
        }
    }
    cnt = 0;
    for(int i = n-1; i >= 0; i--){
        if(s[i]==')') cnt++;
        else{
            if(cnt==0) b++;
            else cnt--;
        }
    }
    rep(i, 0, a) cout << '(';
    cout << s;
    rep(i, 0, b) cout << ')';
    coel;

    return 0;
}
