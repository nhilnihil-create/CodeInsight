#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, sum = 0;
    cin >> n;
    int l[n * 2];
    for (int i = 0; i < n * 2; ++i)
        cin >> l[i];
    sort(l, l + n * 2);
    for (int i = 0; i < n * 2; i += 2)
        sum += l[i];
    cout << sum;
}