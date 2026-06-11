#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>T(N);
    int sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> T[i];
        sum+=T[i];
    }
    int M;
    cin >> M;
    for(int i = 0; i < M; i++) {
        int P,X;
        cin >> P >> X;
        P--;
        cout << sum-T[P]+X << endl;
    }
}
