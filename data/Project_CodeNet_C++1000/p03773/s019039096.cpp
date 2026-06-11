#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    for (int i = 0; i < b; ++i) {
        if (a == 23) a = 0;
        else a++;
    }
    cout << a << endl;
}