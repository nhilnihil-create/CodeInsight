#include <bits/stdc++.h>

using namespace std;

int A[200005];
int pos[200005];
int main() {
    int n; 
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", A + i);
        pos[A[i]] = i;
    }
    set<int> s;
    s.insert(0);
    s.insert(n + 1);
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        int p = pos[i];
        s.insert(p);
        auto p_index = s.find(p);
        auto r = ++p_index;
        auto l = --(--p_index);

        res +=  1LL * i * (p - *l) * (*r - p);
    }
    printf("%lld\n", res);
    return 0;
}
