#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a, ll b){
    if(a < b)  swap(a,b);
    if(a%b==0) return b;
    else return gcd(b,a%b);
}
ll ngcd(vector<ll> a){
    ll res;
    res = a[0];
    for(int i = 1; i < a.size() && res != 1; i++) {
        res = gcd(a[i], res);
    }
    return res;
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
ll nlcm(vector<ll> numbers) {
    ll res;
    res = numbers[0];
    for (ll i = 1; i < numbers.size(); i++) {
        res = lcm(res, numbers[i]);
    }
    return res;
}
ll nCr(ll n, ll r){
    ll a = 1;
    ll b = 1;
    rep(i,r){
        a *= n - i;
        b *= r - i;
        ll c = gcd(a,b);
        a /= c;
        b /= c;
    }
    return a/b;
}
ll max(ll a,ll b){
    if(a > b) return a;
    else return b;
}
int main(){
    cout << fixed << setprecision(10);
    int n,p;
    cin >> n >> p;
    int a = 0, b = 0;
    rep(i,n){
        int x;
        cin >> x;
        if(x%2 == 0) a++;
        else b++;
    }
    ll ans = 0;
    if(p == 0){
        rep(i,b+1){
            if(i%2 != 0) ans += nCr(b,i);
        }
        cout << max(ans,1LL) * (1LL<<a) << endl;
    }else{
        rep(i,b+1){
            if(i%2 == 0) ans += nCr(b,i);
        }
        if(b == 0){
            cout << 0 << endl;
            return 0;
        }
        cout << ll(max(ans,1LL)) * (1LL<<a) << endl;
    }
    return 0;
}