#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define MOD 1000000007
#define ALL(obj) (obj).begin(),(obj).end()
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

ll x[1010000];
ll fib(ll b){
    if (b==1)return 0;
    if (b==2)return 0;
    if (b==3)return 1;
    if (x[b]!=-1)return x[b];
    x[b]=(fib(b-1)+fib(b-2)+fib(b-3))%10007;
    return x[b];
}

int main() {
    ll n;
    cin >> n;
    ll a[n];
    for (ll i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    ll ans=1,c=0;
    for (ll i=1;i<n;i++){
        if (a[i-1]!=a[i])ans++;
        else{
            c++;
        }
    }
    if (c%2)ans--;
    cout << ans << endl;
    return 0;
}
