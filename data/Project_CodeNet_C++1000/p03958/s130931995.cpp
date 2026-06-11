// 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <set>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int K, T;
    cin >> K >> T;
    vector<int> a(T);
    for (int i = 0; i < T; ++i) cin >> a[i];
    if (T == 1)
    {
        cout << a[0] - 1 << endl;
        return 0;
    }
    sort(a.begin(), a.end(), std::greater<int>());
    if (a[0] == a[1] || a[0] == a[1] + 1 )
    {
        cout << 0 << endl;
        return 0;
    }
    int s = 0;
    for (int i = 1; i < T; ++i)
    {
        s += a[i];
    }
    int ans = (s - a[0] + 1) >= 0 ? 0 : a[0] - s - 1;
    cout << ans << endl;
    return 0;
}