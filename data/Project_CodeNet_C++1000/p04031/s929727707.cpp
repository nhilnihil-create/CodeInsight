#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, d, s = 0; 
    float sum = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    sum /= n;
    if (sum - floor(sum) <= 0.5) d = floor(sum);
    else d = ceil(sum);
    for (int i = 0; i < n; ++i)
        s += (a[i] - d) * (a[i] - d);
    cout << s;
}