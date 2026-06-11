#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, p = 0, q = 0, k = 1;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);
    for (long long i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1]) k++;
        else k = 1;
        if (p == 0)
        {
            if (k > 1) 
            {
                p = a[i];
                k -= 2;
            }
        }
        else
        {
            if (k > 1) 
            {
                q = a[i];
                break;
            }
        }
    }
    cout << p * q;
}