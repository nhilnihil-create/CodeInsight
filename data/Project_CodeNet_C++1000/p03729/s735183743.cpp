#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int main() {
    string A, B, C;
    
    cin >> A >> B >> C;

    int size_A = A.size();
    int size_B = B.size();

    if ((A[size_A - 1] == B[0]) && (B[size_B - 1] == C[0])) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}