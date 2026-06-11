#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    long long  Q, H, S, D, N;
    cin >> Q >> H >> S >> D >> N;

    long long ans;
    long long min1 = min({4 * Q, 2 * H, S});
    long long min2 = min({8 * Q, 4 * H, 2 * S, D});

    ans = min2 * (N / 2) + min1 * (N % 2);
    cout << ans << endl;

    return 0;
}