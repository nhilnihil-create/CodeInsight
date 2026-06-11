#include <iostream>
// #include <vector>
// #include <map>
// #include <string>
// #include <algorithm>
// #include <set>
// #include <cmath>

using namespace std;
// typedef unsigned long long ull;


int main(int argc, char const *argv[]) {
    int A, B;
    cin >> A >> B;
    if (B != 1 && (A == 1 || A > B)) {
        cout << "Alice" << endl;
    } else if (A != 1 && (B == 1 || B > A)) {
        cout << "Bob" << endl;
    } else {
        cout << "Draw" << endl;
    }
    return 0;
}
