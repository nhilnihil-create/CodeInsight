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

    int n;
    cin >> n;
    vector<pair<int64_t, int64_t>> vs(n);
    for (auto& v : vs)
    {
        cin >> v.first >> v.second;
    }
    sort(vs.begin(), vs.end());

    cout << (vs.back().first + vs.back().second) << endl;

}
