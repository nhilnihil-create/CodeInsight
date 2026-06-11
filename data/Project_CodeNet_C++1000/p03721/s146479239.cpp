#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; 
    long long K; cin >> N >> K;
    vector<pair<int, int>> num(N);
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        num.at(i) = make_pair(x, y);
    }
    sort(num.begin(), num.end());
    for (int j = 0; j < N; j++) {
        K -= num.at(j).second;
        if (K <= 0) {
            cout << num.at(j).first << endl;
            break;
        }
    }
}