#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define all(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
const int mod = 1e9+7;

int main() {
    int n;
    cin >> n;
    int a[n];
    set<int> s;
    int red = 0;
    rep(i, n) {
        cin >> a[i];
        if (a[i] < 3200) s.insert(a[i] / 400);
        else red++;
    }
    int MIN = max((int)s.size(), 1);
    int MAX = (int)s.size() + red;
    printf("%d %d\n", MIN, MAX);
}