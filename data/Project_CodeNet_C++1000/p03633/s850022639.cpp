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
int main(){
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    cout << nlcm(v) << endl;   
    return 0;
}