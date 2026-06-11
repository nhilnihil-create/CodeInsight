#include <iostream>

using namespace std;

int main() {
    string n;
    cin >> n;

    if (n.at(0) == '9' || n.at(1) == '9') {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}
