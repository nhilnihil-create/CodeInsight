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
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    ll minsum = a * (n - 1) + b;
    ll maxsum = a + b * (n - 1);
    ll ans = maxsum - minsum + 1;
    if (ans < 0) ans = 0;
    cout << ans << endl;
    return 0;
}
