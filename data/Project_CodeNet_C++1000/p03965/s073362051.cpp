#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define MOD 998244353
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
bool pairCompare(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.first < secondElof.first;
}
bool pairCompareSecond(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.second < secondElof.second;
}
// 四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll a,ll b){
    if (a%b==0)return(b);
    else return(gcd(b,a%b));
}

int main() {
    string s;
    cin >> s;
    ll gc=0,pc=0,ans=0;
    for (ll i=0;i<s.size();i++){
        if (s[i]=='p'){
            if (gc>pc){
                pc++;
            }else{
                ans--;
                gc++;
            }
        }else{
            if (gc>pc){
                pc++;
                ans++;
            }else{
                gc++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
