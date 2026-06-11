#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, sum = 0;
    bool discard = false;
    cin >> n;
    int s[n];
    for (int i = 0; i < n; i++) 
    {
        cin >> s[i];
        sum += s[i];
    }
    sort(s, s + n);
    if (sum % 10 != 0) cout << sum;
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i] % 10 != 0)
            {
                cout << sum - s[i];
                discard = true;
                break;
            }
        }
        if (discard == false) cout << '0';
    }
}