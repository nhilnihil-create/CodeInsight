#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[3], k = 0, l = 0;
    for (int i = 0; i < 3; ++i)
    {
        cin >> a[i];
        if (a[i] == 5)
            k++;
        else if (a[i] == 7)
            l++;
    }
    if (k == 2 && l == 1)
        cout << "YES";
    else
        cout << "NO";
}