#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b, c; cin >> a >> b >> c;
    if (a == b && b == c) puts("1");
    else if (a == b || b == c || c == a) puts("2");
    else puts("3");
}