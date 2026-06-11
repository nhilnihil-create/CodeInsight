#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <bitset>
#include <list>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <cmath>
#include <tuple>
#include <cassert>
#include <array>
#include <iomanip>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ti = tuple<int, int, int>;

const double eps=1e-14;
const int mod = 1e9 + 7;
const int inf = ((1<<28));
const ll linf = (1LL<<58);

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++)
    {
        if(i%2==0) cout << s[i];
    }
    return 0;
}
