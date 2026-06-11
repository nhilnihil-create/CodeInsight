#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    bool can = false;
    int count = 1;
    int total = a;
    int first = a % b; 
    while(!can) {
        if(total % b == c) {
            can = true;
            break;
        }
        total += a;
        int d = total % b;
        if (d == first) {
            break;
        }
        count++;
    }

    if (can) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}