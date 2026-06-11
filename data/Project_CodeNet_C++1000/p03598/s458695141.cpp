#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, s = 0;
    cin >> n >> k;
    int x[n];
    for (int i = 0; i < n; i++) 
    {
        cin >> x[i];
        s += min(x[i], k - x[i]);
    }
    cout << s * 2;
}