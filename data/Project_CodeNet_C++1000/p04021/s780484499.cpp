#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;




int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    vector <pair <int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        v.emplace_back(x, i);
    }
    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (i % 2 != v[i].second % 2)
            ans++;

    printf("%d\n", ans / 2);




	return 0;
}


