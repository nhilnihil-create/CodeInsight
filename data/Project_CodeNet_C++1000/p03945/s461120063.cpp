#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    string s;
    cin >> s;
    int n = s.size();
    char c = s[0];
    int ans = 0;
    for(int i = 1; i < n; i++){
        if (s[i] != c){
            ans++;
            c = s[i];
        }
    }
    c = s[n-1];
    int sum = 0;
    for(int i = n-2; i >= 0; i--){
        if (s[i] != c){
            sum++;
            c = s[i];
        }
    }
    ans = min(ans, sum);
    cout << ans << endl;
    return 0;
}