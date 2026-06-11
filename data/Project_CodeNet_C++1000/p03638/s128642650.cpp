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

int main() {
    ll h,w,n;
    cin >> h >> w >> n;
    ll a[n];
    for (ll i=0;i<n;i++)cin >> a[i];
    ll x[h*w],c=0;
    for (ll i=0;i<n;i++){
        for (ll j=0;j<a[i];j++){
            x[c]=i+1;
            c++;
        }
    }
    ll ans[h][w],o=0;
    for (ll i=0;i<w;i++){
        if (i%2){
            for (ll j=0;j<h;j++){
                ans[j][i]=x[o];
                o++;
            }
        }else{
            for (ll j=h-1;j>=0;j--){
                ans[j][i]=x[o];
                o++;
            }
        }
    }
    for (ll i=0;i<h;i++){
        for (ll j=0;j<w;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
