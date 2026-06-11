#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    bool check = 0;

    for(int i = 0; i < B; i++) {
        if((i*A)%B == C) {
            check = 1;
        }
    }
    
    if(check) {
    cout << "YES" << endl;
    } else {
    cout << "NO" << endl;
    }

    return 0;
}