#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<utility>

#define int long long
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;
#define u_b upper_bound
#define l_b lower_bound


signed main() {
    int X, Y;
    cin >> X >> Y;
    if (X > Y)swap(X, Y);
    Y -= X;
    X = 0;
    if (Y <= 1) {
        cout << "Brown" << endl;
    } else {
        cout << "Alice" << endl;
    }
    return 0;
}
