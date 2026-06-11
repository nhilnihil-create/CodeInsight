#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string O, E;
    cin >> O >> E;
    for(int i = 0; i < O.size(); i++) {
        if(O.size() - E.size() && O.size() - 1 == i) {
            cout << O.at(i);
            break;
        }
        cout << O.at(i) << E.at(i);
    }
    cout << endl;


    return 0;
}