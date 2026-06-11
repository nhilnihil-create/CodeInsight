#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const long long int MOD = 1000000007;
int main() {
    long long int N, ans = 1; cin >> N;
    for (int i = 1; i <= N; ++i)  {
        ans *= i;
        ans = ans % MOD;
    }
    cout << ans << endl;
}
