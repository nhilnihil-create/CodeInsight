#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    vector<pair<int, int>> P(N);
    for (int i = 0; i < N; ++i) cin >> P[i].first >> P[i].second;
    sort(P.begin(), P.end());
    long long int ans = ((P[N - 1].first - P[0].first) + 1) + (P[0].first - 1) + P[N - 1].second;
    printf("%d\n", ans);
}
