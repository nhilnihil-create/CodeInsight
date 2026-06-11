#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    char a, b; cin >> a >> b;
    if (a == 'H' && b == 'H') puts("H");
    if (a == 'H' && b == 'D') puts("D");
    if (a == 'D' && b == 'H') puts("D");
    if (a == 'D' && b == 'D') puts("H");

}