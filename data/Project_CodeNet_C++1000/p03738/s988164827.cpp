#include<iostream>
using namespace std;

int main() {
    string A, B; cin >> A >> B;
    if (A.size() > B.size()) {
        cout << "GREATER" << endl;
    } else if (A.size() == B.size()) {
        for (int i = 0; i < A.size(); i++) {
            if (A[i] - '0' > B[i] - '0') {
                cout << "GREATER" << endl;
                return 0;
            } else if (A[i] - '0' < B[i] - '0') {
                cout << "LESS" << endl;
                return 0;
            }
        }
        cout << "EQUAL" << endl;
    } else {
        cout << "LESS" << endl;
    }
}
