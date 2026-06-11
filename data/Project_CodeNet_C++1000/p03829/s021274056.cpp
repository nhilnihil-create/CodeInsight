#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
//using namespace boost::multiprecision;
typedef long long int ll;
typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
bool pairCompare(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.first < secondElof.first;
}
bool pairCompareSecond(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.second < secondElof.second;
}
#define MAX_N 100100
#define MOD 998244353
// 四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
 
ll gcd(ll a,ll b){
    if (a%b==0)return(b);
    else return(gcd(b,a%b));
}

int main(){
    ll n,a,b;
    cin >> n >> a >> b;
    ll x[n];
    for (ll i=0;i<n;i++)cin >> x[i];
    ll ans=0;
    for (ll i=1;i<n;i++){
        if ((x[i]-x[i-1])*a<b){
            ans+=(x[i]-x[i-1])*a;
        }else{
            ans+=b;
        }
    }
    cout << ans << endl;
    return 0;
}