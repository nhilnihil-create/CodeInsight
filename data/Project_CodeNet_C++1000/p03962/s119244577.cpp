#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const double pi = acos(-1);
const int maxn = 2e6 + 10;
const double eps = 1e-8;
const ll mod = 1e9 + 7;
const ull base = 131;
const ull mod1 = 1e9 + 9;
const ull mod2 = 1610612741;

set<int> s;

int main()
{
    for (int i = 1; i < 4; ++i)
    {
        int x;
        scanf("%d", &x);
        s.insert(x);
    }
    printf("%d\n", s.size());
        
	return 0;
}