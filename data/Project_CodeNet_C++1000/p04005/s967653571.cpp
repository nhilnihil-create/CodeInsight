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
    long long int ans = 0;
    vector<long long int> D(3);
    cin >> D[0] >> D[1] >> D[2];

    sort(D.begin(), D.end());

    if (D[0] * D[1] * D[2] % 2 == 0) {
        ans = 0;
    }
    else {
        ans = D[0] * D[1];
    }

    cout << ans;

    return 0;
}