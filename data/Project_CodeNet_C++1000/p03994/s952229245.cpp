#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<sstream>
#include<map>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1;i <=n;i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(a) a.begin(),a.end()
typedef long long ll;
typedef long double ld;
const ll MOD =  1000000007;
const ll INF =  1LL << 60;
ll n, m, x, y,z,w,h, sum= 1, ans = 0;
int main() {
    string s; cin >> s >> m;
    rep(i, s.size()) {
        if (s[i] == 'a') continue;
        x = 'z' - s[i] + 1;
        if (x <= m) {
            m -= x;
            s[i] = 'a';
        }
    }if (m == 0) {
        cout << s << endl;
        return 0;
    }
    m %= 26;
    char c = (s.back() + m);
    s[s.size() - 1] = c;
    cout << s << endl;
}