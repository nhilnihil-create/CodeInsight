#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>

using namespace std;

int main() {
    long long int N, tmp = -1, count = 0, ans = 0;
    cin >> N;

    vector<long long int>A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < N; i++) {
        if (A[i] != tmp) {
            ans += count % 2;
            tmp = A[i];
            count = 1;
        }
        else {
            count++;
        }
    }
    
    ans += count % 2;

    cout << ans;

    return 0;
}
