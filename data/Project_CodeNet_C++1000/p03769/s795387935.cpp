#include <cstdio>
#include <vector>
#define ll long long
#define rep(i, j, k) for (i=j;i<=k;i++)
using namespace std;
ll n;
int i, k;
vector<int> a;

void solve(ll n, int &k) {
    if (n == 1) {
        a.push_back(1);
        k = 1;
        return;
    }
    if (n & 1) {
        solve((n - 1) / 2, k);
        k++;
        a.push_back(k);
    } else {
        solve(n - 1, k);
        k++;
        a.insert(a.begin(), k);
    }
}

int main() {
    scanf("%lld", &n);
    solve(n, k);
    rep(i, 1, k) a.push_back(i);
    printf("%d\n", a.size());
    rep(i, 0, a.size() - 1) printf("%d ", a[i]);
    return 0;
}