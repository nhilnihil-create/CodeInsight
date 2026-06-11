#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INF INT_MAX // 2147483647
#define INFLL LLONG_MAX // 9223372036854775807
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define per(i, n) for(ll i=((ll)(n))-1; i>=0; i--)
#define perf(i, n) for(ll i=((ll)(n)); i>0; i--)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    ll n, ans = 0, pre = 0; cin >> n;
    vector<string> s(2);
    cin >> s[0] >> s[1];

    // ブロックの置き方は2通りしかないため、左から順に処理していく
    // [置き方1] 縦に1個（2*1マス）
    //　最も左なら3通り、置き方1の後なら2通り、置き方2の後なら1通り
    // [置き方2] 横に2個（2*2マス）
    //　最も左なら6通り、置き方1の後なら2通り、置き方2の後なら3通り

    for(ll i=0; i<n; i++){
        // 置き方1の場合
        if(s[0][i] == s[1][i]){
            // 最も左の場合
            if(i == 0){
                ans = 3;
                pre = 1;
            }
            // 置き方1の後の場合
            else if(pre == 1){
                ans = (ans*2)%MODV;
                pre = 1;
            }
            // 置き方2の後の場合
            else{
                ans = ans*1;
                pre = 1;
            }
        }
        // 置き方2の場合
        else{
            // 最も左の場合
            if(i == 0){
                ans = 6;
                pre = 2;
            }
            // 置き方1の後の場合
            else if(pre == 1){
                ans = (ans*2)%MODV;
                pre = 2;
            }
            // 置き方2の後の場合
            else{
                ans = (ans*3)%MODV;
                pre = 2;
            }
            // 2個分読み取るのでその分iを増やす
            i++;
        }
    }

    // 答えの出力
    cout << ans << endl; 
}