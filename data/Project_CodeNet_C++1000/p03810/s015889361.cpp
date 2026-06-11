#include <bits/stdc++.h>
using namespace std;

const int DIM = 100005;

int arr[DIM];

int getgcd(int x, int y) {
    return !y ? x : getgcd(y, x % y);
}

bool solve(int n)
{
    int nr = 0;
    for (int i = 1; i <= n; ++i)
        nr += (arr[i] & 1);

    if ((n - nr) & 1) return true;
    if (nr >= 2) return false;
    
    for (int i = 1; i <= n; ++i) if (arr[i] & 1) {
        if (arr[i] == 1)
            return false;
        --arr[i];
    }
    
    int gcd = arr[1];
    for (int i = 1; i <= n; ++i)
        gcd = getgcd(gcd, arr[i]);
    
    for (int i = 1; i <= n; ++i)
        arr[i] /= gcd;
    
    return !solve(n);
}

int main(void)
{
    int n; cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    
    cout << (solve(n) ? "First" : "Second");
    return 0;
}