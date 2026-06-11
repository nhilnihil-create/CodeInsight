#include <bits/stdc++.h>
using namespace std;
int main(void){
    vector<char> A(3);
    for (int i = 0; i < 3; i++) {
        cin >> A.at(i);
    }
    int C = 0;
    int D = 0;
    for (int i = 0; i < 3; i++) {
        if (A.at(i) == '5') {
            C++;
        }
        else if (A.at(i) == '7') {
            D++;
        }
    }
    if (C == 2 && D == 1) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}