#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
int main() {
    int N; cin >> N;
    vector<int> L(2 * N, 0);
    for (int i = 0; i < 2 * N; i++) cin >> L[i];
    sort(L.begin(), L.end(), greater<int>());
    int sum = 0;
    for (int i = 0; i < 2 * N; i += 2) sum += min(L[i], L[i + 1]);
    printf("%d\n", sum);
}
