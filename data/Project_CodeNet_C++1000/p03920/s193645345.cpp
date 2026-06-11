#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n;

    int sum = 0, t = 0;
    for (;sum < n; sum += ++t);

    for (; t; t--) if (n >= t) cout << t << endl, n -= t;

    return 0;
}