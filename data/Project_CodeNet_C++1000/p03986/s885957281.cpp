#pragma region header
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rev(i, n) for(int i = (int)(n - 1); i >= 0; i--)
#define rev1(i, n) for(int i = (int)(n); i > 0; i--)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define resort(v) sort((v).rbegin(), (v).rend())
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
using ll = long long;
using P = pair<int, int>;
/* ----------------よく使う数字や配列----------------- */
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
constexpr ll mod = 1e9+7;
constexpr int inf = INT32_MAX/2;
constexpr ll INF = LLONG_MAX/2;
constexpr long double eps = DBL_EPSILON;
constexpr long double pi = 3.141592653589793238462643383279;
/* ----------------------end----------------------- */

/* --------------------テンプレート------------------ */
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
/* ----------------------end----------------------- */

/* --------------------ライブラリ-------------------- */
ll fact(int i) {       //階乗
    if (i == 0) return 1;
    return (fact(i - 1)) * i % mod;
}
ll gcd(ll a, ll b) {        //最大公約数
    if(b == 0) return a;
    return gcd(b, a % b); 
}
ll lcm(ll a, ll b) {      //最小公倍数
    return a * b / gcd(a, b);
}
int keta(ll n) {        //桁数を求める
    if(n == 0) return 1;
    int count = 0;
    while(n != 0) {
        n /= 10;
        count++;
    }
    return count;
}
ll ketasum(ll n) {    //各桁の和
    ll sum = 0;
    while(n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
/* ----------------------end----------------------- */
#pragma endregion
signed main() {
    string s;cin >> s;
    // reverse(all(s));
    int ans =0;
    int count = 0;
    rev(i, s.size()) {
        if(s[i]=='T') count++;
        else if(count>0){
            ans+=2;
            count--;
        }
    }
    cout << s.size() - ans << endl;
    // int flag = 0;
    /*int ans = s.size();
    rep(i, s.size()) {
        if(s[i]=='S') {
            if(i>0)if(s[i-1]=='T')ans-=count*2;
            /*if(flag==1) {
                ans-=count;
                flag=0;
            }*/
            /*count++;
        }
        else if(s[i]=='T'&&count>0) {
            // ans-=count*2;
            count++;
            // flag = 1;
        }
    }
    cout << max(ans,0LL) << endl;*/
    /*// reverse(all(s));
    int count = 0;
    bool ok = false;
    // if(s.back()!='T')
    rev(i, s.size()) {
        if(s[i]=='T') {
            count++;
            chmax(count,0LL);
        }
        else {
            count--;
            chmax(count,0LL);
        }
    }
    cout << s.size()-count << endl;*/
    /*int count = 0;
    rep(i, s.size()) {
        if(s[i]=='T') count++;
        else count--;
    }*/
    /*rep(q, 100000) {
        rep(i, s.size()-1) {
            if(s[i]=='S'&&s[i+1]=='T') {
                s.erase(s.begin()+i,s.begin()+i+2);
                // cout << s << endl;
            }
        }
    }
    
    cout << s.size() << endl;*/
    return 0;
}