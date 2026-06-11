#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, t[1000000], m = 0, k;
    cin >> n;
    int a[n];
    for (int i = 0; i < 1000000; i++) t[i] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        t[a[i]]++;
        t[a[i] + 1]++;
        t[a[i] + 2]++;
    }
    for (int i = 0; i < 1000000; i++)
        if (m < t[i]) m = t[i];
    cout << m;
}