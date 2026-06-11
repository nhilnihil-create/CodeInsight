#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, j = 0, s = 0;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
        b[i] = 1;
    }
    sort(a, a + n);
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1]) b[j]++;
        else j++;
    }
    for (int i = 0; i <= j; i++) 
        s += b[i] % 2;
    cout << s;
}