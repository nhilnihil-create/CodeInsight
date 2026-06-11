#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

void dfs(string s, string tmp, int cnt, vector<string> &ret) {
    if ((int)s.size() == cnt) {
        //cout << tmp << endl;
        ret.push_back(tmp);
        return;
    }
    dfs(s, tmp+s[cnt], cnt+1, ret);
    if (cnt != 0) dfs(s, tmp+"+"+s[cnt], cnt+1, ret);
    return;
}

int main() {
    string s;
    cin >> s;
    vector<string> ret;
    dfs(s, "", 0, ret);
    ll ans = 0;
    for (auto a: ret) {
        int idx = 0;
        //cout << (int)a.size() << endl;
        while(idx < (int)a.size()){
            string tmp = "";
            while(a[idx]!='+' && idx < (int)a.size()) {
                tmp += a[idx];
                ++idx;
            }
            reverse(tmp.begin(), tmp.end());
            ll num = 0;
            ll keta = 1;
            rep(i, (int)tmp.size()) {
                num += (tmp[i] - '0') * keta;
                keta *= 10LL;
            }
            //cout << num << endl;
            ans += num;
            ++idx;
        }
    }
    cout << ans << endl;
    return 0;
}
