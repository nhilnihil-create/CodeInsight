#pragma region header
#include <bits/stdc++.h>
using namespace std;
#define int long long
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
constexpr ll inf = INT32_MAX/2;
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
    return a / gcd(a, b) * b ;
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
bool isprime(int n) { //素数判定
    if(n==1)return false;
    if(n==2)return true;
    for(int i = 2;i<=sqrt(n);i++) {
        if(n%i==0) return false;
    }
    return true;
}
/* ----------------------end----------------------- */
#pragma endregion
signed main() {
    string s,t;cin >> s >> t;
    vi sa(s.size()+1),sb(s.size()+1),ta(t.size()+1),tb(t.size()+1);
    sa[0]=sb[0]=ta[0]=tb[0]=0;
    rep(i, s.size()) {
        if(s[i]=='A') sa[i+1]++;
        else sb[i+1]++;
        sa[i+1]+=sa[i];
        sb[i+1]+=sb[i];
    }
    rep(i, t.size()) {
        if(t[i]=='A') ta[i+1]++;
        else tb[i+1]++;
        ta[i+1]+=ta[i];
        tb[i+1]+=tb[i];
    }
    int q;cin >> q;
    rep(x, q) {
        int a,b,c,d;cin >> a >> b >> c >> d;
        int SA = sa[b]-sa[a-1],SB = sb[b]-sb[a-1],TA = ta[d]-ta[c-1],TB = tb[d]-tb[c-1];
        int flag;
        if(SA>=SB) flag=1;
        else flag=0;
        int k = max(SA,SB)-min(SA,SB);
        int Flag;
        if(TA>=TB) Flag = 1;
        else Flag = 0;
        int l = max(TA,TB) - min(TA,TB);
        k%=3,l%=3;
        if(flag==Flag) {
            if(k==l) cout << "YES\n";
            else cout << "NO\n";
        }
        else {
            if(k*2==l||l*2==k) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}