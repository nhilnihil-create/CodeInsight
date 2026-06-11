#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n], odd = 0, even = 0, four = 0;
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
        if (a[i] % 2 == 1) odd++;
        else if (a[i] % 4 == 2) even++;
        else four++;
    }
    if (even == 0 && odd <= four + 1) cout << "Yes";
    else if (even > 0 && odd <= four) cout << "Yes";
    else cout << "No";
}