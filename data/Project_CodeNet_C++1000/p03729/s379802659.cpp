#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    string A, B, C;
    cin >> A >> B >> C;
    if (A.back() == B.front() && B.back() == C.front()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
