#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X.at(i);
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += min(X.at(i), K - X.at(i));
    }
    cout << sum * 2 << endl;
}