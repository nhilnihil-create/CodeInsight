#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題
int main() {
    int k, s;
    cin >> k >> s;
    int count = 0;
    map<int, int> m;
    rep(i, k + 1) {
        rep(j, k + 1) {
            int z = s - i - j;
            if (0 <= z && z <= k) {
                count++;
            }
        }
    }
cout<<count<<endl;
    return 0;
}
