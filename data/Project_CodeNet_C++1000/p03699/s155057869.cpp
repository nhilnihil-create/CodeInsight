#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <utility>
#include <iomanip>
#include <numeric>
#include <climits>
#include <algorithm>
#include <cstdint>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> niz(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> niz[i];
        sum += niz[i];
    }
    sort(niz.begin(), niz.end());
    if (sum % 10)
    {
        cout << sum;
        return 0;
    }
    for (auto x : niz)
    {
        if (x % 10)
        {
            cout << sum - x;
            return 0;
        }
    }
    cout << 0;
}