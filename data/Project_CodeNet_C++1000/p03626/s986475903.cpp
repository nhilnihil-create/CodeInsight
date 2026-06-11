#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007,mod2 = 998244353;

void chmin(long long &a, long long b) { if (a > b) a = b; }
void chmax(long long &a, long long b) { if (a < b) a = b; }
const long long INF = 1LL<<60;
ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

//重みある時
using Edge = pair<int,int>;
using Graph = vector<vector<Edge> >;

vector<string> S(100010);  // mod kごとにわける

int main() {
    ll n;
    string s1,s2;
    cin >> n;
    cin >> s1 >> s2;
    ll ans;
    if(s1[0] == s2[0]){  // 最初縦が同じ
        ans = 3;
        for (int i = 1; i < n; ++i) {
            if(s1[i-1] == s2[i-1] && s1[i] == s2[i]) ans *= 2,ans %= mod;  // 縦縦
            else if(s1[i-1] == s2[i-1] && s1[i] != s2[i]){     // 縦横
                ans *= 2,ans %= mod;
                i++;
            }else if(s1[i-1] != s2[i-1] && s1[i] == s2[i]){  // 横縦
                ans *= 1;
            }else if(s1[i-1] != s2[i-1] && s1[i] != s2[i]){  // 横横
                ans *= 3,ans %= mod;
                i++;
            }
        }
    }
    else{    // 最初横同じ
        ans = 6;
        for (int i = 2; i < n; ++i) {
            if(s1[i-1] == s2[i-1] && s1[i] == s2[i]) ans *= 2,ans %= mod;  // 縦縦
            else if(s1[i-1] == s2[i-1] && s1[i] != s2[i]){     // 縦横
                ans *= 2,ans %= mod;
                i++;
            }else if(s1[i-1] != s2[i-1] && s1[i] == s2[i]){  // 横縦
                ans *= 1;
            }else if(s1[i-1] != s2[i-1] && s1[i] != s2[i]){  // 横横
                ans *= 3,ans %= mod;
                i++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
