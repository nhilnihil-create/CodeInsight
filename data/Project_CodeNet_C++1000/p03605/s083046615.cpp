#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string N;
    cin >> N;
    if((N[0] ^ 0x39) && (N[1] ^ 0x39)) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
    return 0;
}
