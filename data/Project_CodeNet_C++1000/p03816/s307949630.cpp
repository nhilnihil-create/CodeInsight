#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 , -1};
signed main() {
    int N;
    cin >> N;
    vector<int>A(N);
    set<int>Set;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        Set.insert(A[i]);
    }
    cout << Set.size()-(N-Set.size())%2 << endl;
    return 0;
}
