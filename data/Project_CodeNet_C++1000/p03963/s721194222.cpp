#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    cout << K*(int)pow(K - 1, N - 1) << endl;

    return 0;
}