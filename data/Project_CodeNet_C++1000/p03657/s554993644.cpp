#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int main() {
    int A, B;

    cin >> A >> B;

    if (A % 3 == 0) {
        cout << "Possible" << endl;
        return 0;
    } else if (B % 3 == 0) {
        cout << "Possible" << endl;
        return 0;
    } else if ((A + B) % 3 == 0) {
        cout << "Possible" << endl;
        return 0;
    }

    cout << "Impossible" << endl;
    return 0;
}