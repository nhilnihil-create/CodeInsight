#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.get();

    string one, two;
    getline(cin, one);
    getline(cin, two);

    constexpr int kMod = 1e9 + 7;
    int res = 1;

    int occupied = 0;
    size_t i = 0;

    while (i < one.size()) {
        if (one[i] == two[i]) {
            res = (1LL * res * (3 - occupied)) % kMod;
            occupied = 1;
            i += 1;
        } else {
            res = (1LL * res * (occupied == 2 ? 3 : occupied == 1 ? 2 : 6)) % kMod;
            occupied = 2;
            i += 2;
        }
    }

    cout << res << "\n";
    return 0;
}
