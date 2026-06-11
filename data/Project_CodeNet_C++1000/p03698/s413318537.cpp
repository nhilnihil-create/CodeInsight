#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string S;
    vector<bool> abc(26,0);
    cin >> S;
    for(int i = 0; i < S.size(); i++) {
        if(abc.at(S.at(i) - 'a')) {
            cout << "no" << endl;
            return 0;
        } else {
            abc.at(S.at(i) - 'a') = 1;
        }
    }
    cout << "yes" << endl;

    return 0;
}