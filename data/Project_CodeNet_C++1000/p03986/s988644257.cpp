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
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    string x;
    cin >> x;
    int n = x.size();
    stack<char> st;
    rep(i, n) {
        if (st.empty()) {
            st.push(x[i]);
        }
        else if (st.top() == 'S' && x[i] == 'T') {
            st.pop();
        }
        else {
            st.push(x[i]);
        }
    }
    cout << st.size() << endl;
    return 0;
}
