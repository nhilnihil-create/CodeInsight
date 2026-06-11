#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, m = 1;
    cin >> n;
    int a[n + 1];
    bool used[n + 1], trained = false;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        used[i] = false;
    }
    used[1] = true;
    k = a[1];
    for (int i = 0; i < n; i++)
    {
        if (k == 2)
        {
            trained = true;
            break;
        }
        if (used[k] == true) break;
        used[k] = true;
        int l = a[k];
        k = l;
        m++;
    }
    if (trained == true) cout << m;
    else cout << "-1";
}