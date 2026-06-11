#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define MOD 998244353
template<class T>inline bool chmax(T& a,T b){if (a<b){a=b;return 1;}return 0;}
template<class T>inline bool chmin(T& a,T b){if (a>b){a=b;return 1;}return 0;}
const long long INF = 1LL << 60;
bool pairCompare(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.first < secondElof.first;
}
bool pairCompareSecond(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.second < secondElof.second;
}
//四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct edge{//グラフに使うヤツ
    ll from,to,cost;
};

typedef vector<vector<edge> > G;
ll gcd(ll a,ll b){
    if (a%b==0)return(b);
    else return(gcd(b,a%b));
}

int main() {
    ll n;
    cin >> n;
    ll a[n];
    for (ll i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    vector<ll> x;
    for (ll i=n-1;i>=1;i--){
        if (a[i]==a[i-1]){
            x.push_back(a[i]);
            i--;
        }
    }
    if (x.size()<2){
        cout << 0 << endl;
        return 0;
    }
    cout << x[0]*x[1] << endl;
    return 0;
}