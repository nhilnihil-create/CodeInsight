#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int k, t;
    cin >> k >> t;
    vector<int> as(t);
    for (auto& a : as)
    {
        cin >> a;
    }
    sort(as.begin(), as.end());

    const auto mx = *max_element(as.begin(), as.end());

    cout << max(0, k - 2 * (k - mx) - 1) << endl;
}
