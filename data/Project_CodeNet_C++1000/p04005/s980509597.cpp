#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 100000;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int A,B,C;
    cin >> A >> B >> C;
    if(A%2 == 0 || B%2 == 0 || C%2 == 0) {
        cout << 0 << endl;
        return 0;
    }
    cout << min({A*B,A*C,B*C}) << endl;
}
