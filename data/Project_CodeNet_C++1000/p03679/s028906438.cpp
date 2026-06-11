#include "bits/stdc++.h"

using namespace std;

int main() {
    int X, A, B;
    cin >> X >> A >> B;

    int diff = B - A;

    if (diff <= 0) cout << "delicious" << endl;
    else if (diff > X) cout << "dangerous" << endl;
    else cout << "safe" << endl;
    
    return 0;
}