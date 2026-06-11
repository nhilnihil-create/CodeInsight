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
    int n;
    string s;
    cin >> n >> s;
    int l = 0;
    int r = 0;
    string ans = s;
    int r_accum_num = 0;
    int l_accum_num = 0;
    stack<char> st;
    rep(i, n) {
        if (st.empty()) st.push(s[i]);
        else if (st.top() == '(' && s[i] == ')') {
            st.pop();
        }
        else {
            st.push(s[i]);
        }
    }
    if (st.empty()) {
        cout << s << endl;
        return 0;
    }
    while(1) {
        if (st.empty()) break;
        if (st.top() == '(') ++l;
        if (st.top() == ')') ++r;
        st.pop(); 
    }
    ans = s;
    rep(i, l) ans += ')';
    rep(i, r) ans = '(' + ans;
    cout << ans << endl;
    return 0;
}
