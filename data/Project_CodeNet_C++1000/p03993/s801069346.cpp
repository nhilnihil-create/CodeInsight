#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>


using namespace std;

int main() {
    int N, tmp, ans = 0;
    cin >> N;

    vector<int> K(N);
    vector<bool> A(N);

    for (int i = 0; i < N; i++) {
        cin >> K[i];
    }

    for (int i = 0; i < N; i++) {
        if (A[i] == true) {
            continue;
        }
        if (i + 1 == K[K[i] - 1]) {
            ans ++;
            A[K[i] -1] = true;
        }
    }

    cout << ans;

    return 0;
}