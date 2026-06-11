#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int X,A,B;

    cin >> X >> A >> B;
    if(B <= A) { 
        cout << "delicious\n";
    } else if(B <= (A+X)) {
        cout << "safe\n";
    } else {
        cout << "dangerous\n";
    }
    return 0;
}
