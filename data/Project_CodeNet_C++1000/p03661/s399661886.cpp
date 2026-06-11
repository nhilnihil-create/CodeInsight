#include <vector>
#include <algorithm>
#include <iostream>
#include <array>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;

    vector<int> vs(n);

    ll sum_f = 0;
    ll sum_e = 0;
    for (auto &v : vs)
    {
        cin >> v;
        sum_f += v;
    }
    sum_f -= vs.back();
    sum_e += vs.back();
    ll min_diff = abs(sum_f - sum_e);

    for (int i = vs.size() - 2; i > 0; i--)
    {
        sum_f -= vs[i];
        sum_e += vs[i];
        min_diff = min<ll>(min_diff, abs(sum_f - sum_e));
    }
    cout << min_diff << endl;
}