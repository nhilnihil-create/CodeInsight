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
    long long int N, A, B, ans;
    cin >> N >> A >> B;
    if (A > B || (N == 1 && A != B)) {
        ans = 0;
    }
    else if (A == B) {
        ans = 1;
    }
    else {
        if (N == 2) {
            ans = B - A + 1;
        }
        else {
            ans = B * (N - 1) + A - A * (N - 1) - B + 1;
        }
    }

    cout << ans;

    return 0;
}