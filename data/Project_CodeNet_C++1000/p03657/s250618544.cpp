#include <bits/stdc++.h>
using namespace std;
int main () {
    int a, b;
    cin >> a >> b;
    if ((a%3) * (b%3) * ((a+b)%3)) {
        puts("Impossible");
    }
    else {
        puts("Possible");
    }
}