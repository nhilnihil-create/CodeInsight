#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt[100005] = {};
signed main() {
    int N,A,B;
    cin >> N >> A >> B;
    cout << max(0LL,B*(N-1)+A-(A*(N-1)+B)+1) << endl;
}
