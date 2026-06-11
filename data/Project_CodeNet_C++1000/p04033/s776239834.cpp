#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int a,b;
    cin >> a >> b;
    if(a <= 0 && b >= 0) {
        cout << "Zero"  << endl;
    }
    else if(a >= 1 && b >= 1) {
        cout << "Positive"  << endl;
    }
    else if(abs(b-a)%2 == 0) {
        cout << "Negative" << endl;
    }
    else {
        cout << "Positive" << endl;
    }
}