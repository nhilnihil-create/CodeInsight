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
    int amax = -1;
    for (int i = 0; i < T; ++i) 
    {
        cin >> a[i];
        amax = std::max(amax, a[i]);
    }
    int ans = std::max(amax - 1 - (K - amax), 0);
    cout << ans << endl;
    return 0;
}
