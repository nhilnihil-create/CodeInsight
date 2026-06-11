#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>A(N+1);
    int sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    A[N] = A[0];
    if(sum%((1+N)*N/2)) {
        cout << "NO" << endl;
        return 0;
    }
    int cnt = sum/((1+N)*N/2);
    int res = 0;
    for(int i = 0; i < N; i++) {
        int X = A[i+1]-A[i];
        if(X != cnt) {
            if(X >= cnt) {
                cout << "NO" << endl;
                return 0;
            }
            else if((X-cnt)%N) {
                cout << "NO" << endl;
                return 0;
            }
            res += (X-cnt)/N;
        }
    }
    if(res > N) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
}
