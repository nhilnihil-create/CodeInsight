#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    bool check = 0;
    vector<bool> A(4,0);

    for(int i = 0; i < S.size(); i++) {
        if(S.at(i) == 'N') {
            A.at(0) = 1;
        } else if(S.at(i) == 'W') {
            A.at(1) = 1;
        } else if(S.at(i) == 'S') {
            A.at(2) = 1;
        } else if(S.at(i) == 'E') {
            A.at(3) = 1;
        }
    }
    if(!(A.at(0)^A.at(2)) && !(A.at(1)^A.at(3))) {
        check = 1;
    }
    
    if(check) {
    cout << "Yes" << endl;
    } else {
    cout << "No" << endl;
    }


    return 0;
}