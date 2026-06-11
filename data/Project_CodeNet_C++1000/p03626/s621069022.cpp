#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
//using namespace boost::multiprecision;
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


int main(){
    ll n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    ll ans=1;
    ll x=-1;
    for (ll i=0;i<n;i++){
        if (x==-1){
            if (s[i]==t[i]){
                ans*=3;
                x=0;
            }else{
                ans*=6;
                x=1;
                i++;
            }
        }else if (x==0){
            if (s[i]==t[i]){
                ans*=2;
            }else{
                ans*=2;
                x=1;
                i++;
            }
        }else{
            if (s[i]==t[i]){
                x=0;
            }else{
                ans*=3;
                i++;
            }
        }
        ans%=MOD;
    }
    cout << ans << endl;
    return 0;
}
