#include <iostream>

using namespace std;

int FindStep(int n)
{
    auto step = 0;
    auto power = (1 << 29);

    while (power > 0) {
        auto new_step = step + power;
        power >>= 1;

        if (1LL * new_step * (new_step + 1) / 2 < n) {
            step = new_step;
        }
    }
    return step + 1;
}

int main()
{
    int n;
    cin >> n;

    auto res = FindStep(n);
    cout << res << "\n";

    return 0;
}
