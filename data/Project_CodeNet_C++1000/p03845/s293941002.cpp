#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <string.h>
#include <stack>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {
    int n;
    cin >> n;
    vector<int>t(n);
    ll sum = 0;
    rep(i, 0, n) {
        cin >> t[i];
        sum += t[i];
    }
    int m;
    cin >> m;
    rep(i, 0, m) {
        int p,x;
        cin >> p >> x;
        if(t[p-1] > x) {
            cout << sum-(t[p-1] - x) << endl;
        } else {
            cout << sum+(x - t[p-1]) << endl;
        }
    }
    return 0;
}
