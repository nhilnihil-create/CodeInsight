#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    ll N, M;
    cin >> N >> M;

    if(N >= M / 2) cout << M / 2 << endl;
    else cout <<  N + (M - (2 * N)) / 4 << endl;
}