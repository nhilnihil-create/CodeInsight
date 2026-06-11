#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    ll x, y; cin >> x >> y;
    if (fabs(x - y) <= 1) cout << "Brown" << endl;
    else cout << "Alice" << endl;
    return 0;
}