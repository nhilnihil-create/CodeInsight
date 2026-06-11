#include "bits/stdc++.h"

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    
    int res = A + B;
    if (res < 10) cout << res << endl;
    else cout << "error" << endl;
    return 0;
}