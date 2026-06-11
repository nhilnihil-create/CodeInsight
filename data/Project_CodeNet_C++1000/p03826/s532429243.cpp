#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

int main() {
    int A, B, C, D;

    cin >> A >> B >> C >> D;

    if ((A * B) > (C * D)) {
        cout << A * B << endl;
    } else if ((A * B) < (C * D)) {
        cout << C * D << endl;
    } else if ((A * B) == (C * D)) {
        cout << A * B << endl;
    }

    return 0;
}