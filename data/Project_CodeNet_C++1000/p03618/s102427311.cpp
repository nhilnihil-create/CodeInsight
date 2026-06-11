#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
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

// ai == ajとなるi, jは、ai+1...aj-1を反転した結果と同じになるため無視してOK
// ai != ajについて、ai...ajを反転したものをb(i,j)と考えた場合、
// b(i,j)がaと文字が異なる最左位置はiであり、同様に文字が異なる最右位置はjとなる。
// b(i,j) = b(x,y)と仮定すると。b(x,y)がaと文字が異なる最左位置はiになるためx=i,
// 同様に最右位置はjになるためy=jとなる。よって、b(i,j) = b(x,y)であれば、i=xかつj=yが成立する。
// 対偶(pならばq　→　qでなければpでない)をとると、i!=x またはj !=yであればb(i,j) != b(x,y)となる。
// よって、ai != ajなるi..jを反転して得られた文字列は全て異なる。
// 上記より、ai != ajなるi<jの組を数え上げ、その組＋1（初期文字列）と計算することで解が得られる。
int main(){
    Init();
    string s; cin >> s;
    ll n = s.size();
    map<char, ll> cnt;
    rep(i, n) cnt[s[i]]++;

    // 全ての組み合わせからai == ajなる組を除く。
    ll ans = n*(n-1)/2;
    for(char c='a'; c<='z'; c++){
        if(cnt[c] <= 1) continue;
        ans -= (cnt[c]*(cnt[c]-1))/2;
    }
    // 元々の文字列分を1個足す
    cout << ans+1 << endl;
}