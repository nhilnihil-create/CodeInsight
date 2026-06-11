#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(j, m) for (int j = 0; j < (int)(m); j++)
#define rep2(i, l, n) for (int i = l; i < (int)(n); i++)


int main() {
    string A,B;
    cin >> A >> B;
    if (A.size() > B.size()) {
        cout << "GREATER" << endl;
    }
    else if (A.size() < B.size()) {
        cout << "LESS" << endl;
    }
    else {
        int flag = 0;
        rep(i,A.size()) {
            if (A[i] > B[i]) {
                cout << "GREATER" << endl;
                flag++;
                break;
            }
            else if (A[i] < B[i]) {
                cout << "LESS" << endl;
                flag++;
                break;
            }
        }
        if (flag == 0) {
            cout << "EQUAL" << endl;
        }
    }
}

