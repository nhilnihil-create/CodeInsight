#include <bits/stdc++.h>
using namespace std;

int main() {
    char a, b;
    cin >> a >> b;
    if (a=='H' && b=='H') cout << "H\n";
    else if (a=='H' && b=='D') cout << "D\n";
    if (a=='D' && b=='H') cout << "D\n";
    else if (a=='D' && b=='D') cout << "H\n";
}