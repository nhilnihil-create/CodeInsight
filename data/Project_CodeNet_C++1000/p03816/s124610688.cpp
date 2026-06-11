#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, s = 0, d = 0, v[100000];
    cin >> n;
    int a[n];
    for (int i = 0; i < 100000; i++) v[i] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        v[a[i] - 1]++;
    }
    for (int i = 0; i < 100000; i++)
    {
        if (v[i] != 0)
        {
            d++;
            s += (v[i] - 1);
        }
    }
    cout << d - s % 2;
}