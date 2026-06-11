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
    int N; cin >> N;
    vector<int> a(N), cnt(100000);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int M = 0;
    if(N != 1) {
        for(int i = 0; i < N; i++) {
            int sum;
            if(i != 0 && i != N - 1) {
                sum = cnt[i] + cnt[i - 1] + cnt[i + 1];
            }
            else if(i == 0) {
                sum = cnt[i] + cnt[i + 1];
            }
            else {
                sum = cnt[i] + cnt[i - 1];
            }
            M = max(M, sum);
        }
    }
    else M = 1;
    cout << M << endl;
    return 0;
}