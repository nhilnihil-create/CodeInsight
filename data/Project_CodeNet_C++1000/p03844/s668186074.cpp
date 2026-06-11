#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int a;
    char op;
    int b;

    cin >> a >> op >> b;

    int ans =0;
    if (op == '+') ans = a+b;
    if (op == '-') ans = a-b;

    cout << ans << endl;
    return 0;
}