#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int x, n;

int main() {
    cin >> x;
    for(n = 1; n * (n + 1) / 2 < x; n ++);
    cout << n << endl;
    return 0;
}