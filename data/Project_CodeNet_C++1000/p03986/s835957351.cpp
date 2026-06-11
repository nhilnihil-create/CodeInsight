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
    string x;
    cin >> x;
    stack<char> s;
    int n = x.size();
    rep(i, n) {
        if (x[i] == 'S') {
            s.push(x[i]);
        }
        else if (x[i] == 'T') {
            if (s.empty() || s.top() != 'S') {
                s.push(x[i]);
            }
            else {
                s.pop();
            }
        }
    } 
    cout << (int)s.size() << endl;
    return 0;
}
