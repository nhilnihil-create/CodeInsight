#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[3], d = 0;
    cin >> a[0];
    for (int i = 1; i < 3; i++) 
    {
        cin >> a[i];
        for (int j = 0; j < i; j++) 
            if (a[i] == a[j]) d++;
    }
    if (d == 1) cout << '2';
    else if (d == 3) cout << '1';
    else cout << '3';
}