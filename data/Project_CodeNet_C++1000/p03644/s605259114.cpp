#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int k2 = 2;
    int a = 1;
    while (k2 <= n) {
      a = k2;
      k2 *= 2;
    }
    cout << a << endl; 
}