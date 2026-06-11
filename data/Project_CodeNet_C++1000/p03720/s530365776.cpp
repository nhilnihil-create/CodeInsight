#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, M; cin >> N >> M;
    vector<int> a(M, 0);
    vector<int> b(M, 0);
    for (int i = 0; i < M; ++i) cin >> a[i] >> b[i];
    for (int i = 1; i <= N; ++i) {
        int cnt = 0;
        for (int j = 0; j < M; ++j) {
            if (i == a[j]) cnt++;
            if (i == b[j]) cnt++;
        }
        printf("%d\n", cnt);
    }
}
