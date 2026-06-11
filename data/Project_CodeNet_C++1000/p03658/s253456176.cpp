#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
int main() {
    int N, K; cin >> N >> K;
    vector<int> L(N, 0);
    for (int i = 0; i < N; ++i) cin >> L[i];
    sort(L.begin(), L.end(), greater<int>());
    int sum = 0;
    for (int i = 0; i < K; ++i) sum += L[i];
    printf("%d\n", sum);
}
