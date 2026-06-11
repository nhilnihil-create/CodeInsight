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
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}

int main(){
    ll n,k,ans=INF;
    cin >> n >> k;
    ll a2[n];
    for (ll i=0;i<n;i++){
        cin >> a2[i];
    }
    for (ll bit=0;bit<=(1<<(n));bit++){
        ll a[n];
        for (ll i=0;i<n;i++)a[i]=a2[i];
        ll mini=a[0],count=0,kc=1;
        for (ll i=1;i<n;i++){
            if ((1<<i)&bit){
                if (a[i]<=mini){
                    count+=(mini-a[i])+1;
                    a[i]=mini+1;
                }
                kc++;
            }else if (a[i]>mini)kc++;
            mini=max(a[i],mini);
        }
        if (kc>=k)ans=min(ans,count);
    }
    cout << ans << endl;
    return 0;
}    
