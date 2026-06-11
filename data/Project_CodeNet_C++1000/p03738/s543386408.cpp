#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    string A, B;
    cin >> A >> B;

    if(A.length() > B.length()) {
        cout << "GREATER" << endl;
        return 0;
    }
    if(A.length() < B.length()) {
        cout << "LESS" << endl;
        return 0;
    }

    for(int i = 0; i < A.length(); i++) {
        if(A[i] > B[i]) {
            cout << "GREATER" << endl;
            return 0;
        }
        if(A[i] < B[i]) {
            cout << "LESS" << endl;
            return 0;
        }
    }

    cout << "EQUAL" << endl;
}