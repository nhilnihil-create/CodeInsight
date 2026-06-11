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

int main() {
    string s;
    cin >> s;
    int n = s.size();
    stack<char> st;
    rep(i, n) {
        if (s[i] == '0' || s[i] == '1') st.push(s[i]);
        else if (st.empty())            continue;
        else                            st.pop();
    }
    vector<char> ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    rep(i, (int)(ans.size())) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
