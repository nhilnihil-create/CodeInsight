#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int N, K; cin >> N >> K;
    vector<int> l(N);
    int sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> l[i];
    }
    sort(l.begin(), l.end());
    reverse(l.begin(), l.end());
    for(int i = 0; i < K; i++) sum += l[i];
    cout << sum << endl;
    return 0;
}