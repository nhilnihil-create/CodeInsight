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
    int N, K;

    cin >> N >> K;

    ans = K * pow(K - 1, N - 1);

    cout << ans;

    return 0;
}