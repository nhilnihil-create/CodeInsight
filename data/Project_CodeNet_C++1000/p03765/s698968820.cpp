#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

// AB, AAA, BBB, BBAA, AABB, BA, ""
// A, BB, BAA, AAB, ABBB, BBBA, AAAA
// B, AA,
// A = 1, B = 2
vector<int> get_dp(string s) {
    vector<int> dp = {0};
    for(char c: s) {
        if (c == 'A') {
            dp.push_back(dp.back()+1);
        } else {
            dp.push_back(dp.back()+2);
        }
    }
    return dp;
}

int main() {
    string s, t;
    cin >> s >> t;
    int q, s1, s2, t1, t2;
    cin >> q;
    auto dp_s = get_dp(s);
    auto dp_t = get_dp(t);
    while(q--) {
        cin >> s1 >> s2 >> t1 >> t2;
        auto sum_s = dp_s[s2] - dp_s[s1-1];
        auto sum_t = dp_t[t2] - dp_t[t1-1];
        if (sum_s %3 == sum_t %3) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}


