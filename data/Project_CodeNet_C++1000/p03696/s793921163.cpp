//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string ans;
    int sum = 0;
    rep(i, n) {
        if(s[i] == '(') {
            sum++;
        } else {
            sum--;
        }
        if(sum < 0) {
            ans += '(';
            sum = 0;
        }
    }
    ans += s;
    rep(i, sum) {
        ans += ')';
    }

    cout << ans << endl;
}