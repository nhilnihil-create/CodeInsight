#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

const int INF = 1e9;
const long long LINF = 1e18;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ans = 1;
    int mode = 0;
    for (int i = 0; i < N - 1; i++) {
        if (mode == 0) {
            if (A[i] < A[i + 1]) {
                mode = 1;
            } else if (A[i] > A[i + 1]) {
                mode = 2;
            }
        } else if (mode == 1) {
            if (A[i] > A[i + 1]) {
                mode = 0;
                ++ans;
            }
        } else if (mode == 2) {
            if (A[i] < A[i + 1]) {
                mode = 0;
                ++ans;
            }
        }
    }

    cout << ans << endl;

    return 0;
}