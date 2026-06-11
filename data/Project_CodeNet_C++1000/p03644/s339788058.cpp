#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;

    int x = 1;
    while (x < n)
        x <<= 1;
    
    if (x > n)
        x >>= 1;

    cout << x << endl;
}
