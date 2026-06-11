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

vector<int> cnt;

int main() {
    string s;
    ll k;
    cin >> s >> k;
    for (int i = 0; i < s.size(); ++i) {
        int banme = s[i] - 'a';  // 何番目のアルファベット a0,b1
        int need = 25 - banme + 1;  // 何回やるか a0,b25
        if(s[i] == 'a') need = 0;

        if(k >= need){
            k -= need;
            s[i] = 'a';
        }
    }

    k %= 26;
    int banme2 = s[s.size()-1] - 'a';
    banme2 += k;
    banme2 %= 26;
    s[s.size()-1] = (char)('a'+banme2);
    cout << s << endl;
    return 0;
}
