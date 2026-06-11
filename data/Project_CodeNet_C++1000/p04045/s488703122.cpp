#include <bits/stdc++.h>
using namespace std;
int check(int a, int b) {
    int k = 0;
    while (a != 0)
    {
        if (a % 10 == b)
        {
            k++;
            break;
        }
        a /= 10;
    }
    if (k == 0) return 1;
    else return 0;
}
int main() {
    int k, n, m;
    cin >> n >> k;
    int d[k];
    for (int i = 0; i < k; ++i)
        cin >> d[i];
    for (int i = n; i < 100000; ++i)
    {
        m = 0;
        for (int j = 0; j < k; ++j)
        {
            if (check(i, d[j]) == 0)
            {
                m++;
                break;
            }
        }
        if (m == 0)
        {
            cout << i;
            break;
        }
    }
}