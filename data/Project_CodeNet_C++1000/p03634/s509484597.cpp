#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
//using namespace boost::multiprecision;
typedef long long int ll;
typedef long double ld;
#define PI 3.141592653589793
#define MOD 1000000007
#define ALL(obj) (obj).begin(),(obj).end()
template<class T>inline bool chmax(T& a,T b){if (a<b){a=b;return 1;}return 0;}
template<class T>inline bool chmin(T& a,T b){if (a>b){a=b;return 1;}return 0;}
const ll INF = 1LL << 62;

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
    ll n,q,k;
    cin >> n;
    vector<pair<ll,ll> > dis[n];
    for (ll i=0;i<n-1;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        dis[a].push_back(make_pair(b,c));
        dis[b].push_back(make_pair(a,c));
    }
    cin >> q >> k;
    ll ans[n];
    k--;
    fill(ans,ans+n,INF);
    ans[k]=0;
    queue<ll> que;
    que.push(k);
    while(!que.empty()){
        ll p=que.front();
        que.pop();
        for (ll i=0;i<dis[p].size();i++){
            ll next=dis[p][i].first;
            if (ans[next]>ans[p]+dis[p][i].second){
                ans[next]=ans[p]+dis[p][i].second;
                que.push(next);
            }
        }
    }
    for (ll i=0;i<q;i++){
        ll x,y;
        cin >> x >> y;
        x--;
        y--;
        cout << ans[x]+ans[y] << endl;
    }
    return 0;
}
