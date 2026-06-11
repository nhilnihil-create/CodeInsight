#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
using ll = long long;
int main() {
    int n;
    scanf("%d", &n);
	map<int, int> ma;
    rep(i, n) {
        int a;
        scanf("%d", &a);
        ma[a]++;
    }
    ll count = 0;
    for (auto itr : ma)
    {
        if(itr.second % 2 != 0) count++;
    }
    printf("%lld\n", count);
    return 0;
}