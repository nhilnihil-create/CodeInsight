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
    vector<int> s(N);
    int sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> s[i];
        sum += s[i];
    }
    if(sum % 10 != 0) cout << sum << endl;
    else {
        int M = 0;
        for(int i = 0; i < N; i++) {
            int sumo = sum - s[i];
            if(sumo % 10 == 0) sumo = 0;
            M = max(M, sumo);
        }
        cout << M << endl;
    }
    return 0;
}