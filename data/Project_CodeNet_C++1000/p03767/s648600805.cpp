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
    long long int N, ans = 0;
    cin >> N;
    vector<int> a(3 * N);

    for (int i = 0; i < 3 * N; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < N; i++) {
        ans += a[3 * N - 2 * (i + 1)];
    }

    cout << ans;

    return 0;

}

