#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k = 0;
    cin >> n;
    while (n != 1)
    {
        n /= 2;
        k++;
    }
    cout << pow(2, k);
}