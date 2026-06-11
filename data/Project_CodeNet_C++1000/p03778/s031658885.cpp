#include <bits/stdc++.h>
using namespace std;

int main() {
    int w,a,b;
    cin >> w >> a >> b;

    cout <<max(0, max(a,b)-(min(a,b)+w));

    return 0;
}