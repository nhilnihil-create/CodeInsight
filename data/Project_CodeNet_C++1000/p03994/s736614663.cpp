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
typedef long long ll;
ll n, m, x, y,z,w,h, sum= 1, ans = 0;
int main() {
    string s; cin >> s >> m;
    rep(i, s.size()) {
        if(s[i] == 'a') continue;
        x = s[i] - 'a';
        if (26 - x <= m) {
            m -= 26 - x;
            s[i] = 'a';
        }
    }m %= 26;
    char c = (s.back() + m);
    s[s.size() - 1] = c;
    cout << s << endl;
}
