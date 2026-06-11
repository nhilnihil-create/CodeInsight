#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, a, b, s = 0;
    cin >> n >> a >> b;
    int x[n];
    cin >> x[0];
    for (int i = 1; i < n; i++)
    {
        cin >> x[i];
        s += min((x[i] - x[i - 1]) * a, b);
    }
    cout << s;
}