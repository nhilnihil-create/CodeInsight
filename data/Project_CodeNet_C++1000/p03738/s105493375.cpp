#include <bits/stdc++.h>
using namespace std;

int main()
{
        string A, B;
        cin >> A;
        cin >> B;
        if (A.length() > B.length()) {
                cout << "GREATER" << endl;
        }
        else if (A.length() < B.length()) {
                cout << "LESS" << endl;
        }
        else {
                for (int i = 0; i < A.length(); ++i) {
                        if (A[i] > B[i]) {
                                cout << "GREATER" << endl;
                                exit(0);
                        }
                        else if (A[i] < B[i]) {
                                cout << "LESS" << endl;
                                exit(0);
                        }
                }
                cout << "EQUAL" << endl;
        }


}
