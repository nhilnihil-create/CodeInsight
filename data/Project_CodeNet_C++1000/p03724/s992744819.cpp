#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    map<int, int>mp;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        mp[a]++;
        mp[b]++;
    }

    for (int i = 1; i <= N; i++) {
        if (mp[i] % 2 == 1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
