#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    string s;
    cin >> s;
    int N = s.size();
    //vec[i]:=それより右をi文字に抑えることのできる最小のindex
    vector<int> vec;
    vec.pb(N);
    map<char, int> mp;
    rep3(i, N-1, 0){
        mp[s[i]]++;
        if(mp.size() == 26){
            vec.pb(i);
            mp.clear();
        }
    }
    //文字列の最小の長さはn
    int n = vec.size();
    s += alpha;
    //左からi文字目に何を使えるか貪欲に調べる
    int now = 0;
    char ans[n];
    rep(i, n){
        rep(j, 26){
            char x = 'a'+j;
            int k = now;
            while(s[k] != x) k++;
            //残りでn-1-i文字を作れれば良い
            if(k >= vec[n-1-i]){
                ans[i] = x;
                now = k+1;
                break;
            }
        }
    }
    rep(i, n) cout << ans[i];
    cout << endl;
}