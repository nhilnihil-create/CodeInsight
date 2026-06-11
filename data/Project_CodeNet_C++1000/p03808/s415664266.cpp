#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define P pair<int, int>
#define F first
#define S second
#define mod 1000000007
#define MOD 998244353
#define INF 40000000000000000
int dx8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy8[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dx4[4] = {-1, 0, 1, 0};
int dy4[4] = {0, -1, 0, 1};
signed main(void) {
    int N;
    cin >> N;
    int A[N];
    int sum = 0;
    rep(i, N) {
        cin >> A[i];
        sum += A[i];
    }
    if(sum % (N * (N + 1) / 2) != 0) {
        cout << "NO" << endl;
        return 0;
    }
    sum = sum / (N * (N + 1) / 2);
    rep(i, N) {
        int X = A[N - 1 - i] + sum - A[(N - i) % N];
        if(X % N != 0 || X < 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
