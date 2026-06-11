#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(), (x).end()
#define OUT(x) std::cout << (x) << std::endl
typedef long long ll;

int main() {
    int A, B;
    cin >> A >> B;
    if (A == B) {
        cout << "Draw" << endl;
        return 0;
    }
    if (A == 1) {
        cout << "Alice" << endl;
        return 0;
    }
    if (B == 1) {
        cout << "Bob" << endl;
        return 0;
    }
    if (A < B) {
        cout << "Bob" << endl;
    } else {
        cout << "Alice" << endl;
    }
}