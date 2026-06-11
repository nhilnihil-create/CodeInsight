#include <bits/stdc++.h>
using namespace std;

int main() {
    string res = "";
    string ope;
    cin >> ope;
    for(int i = 0; i < ope.size(); i++) {
        if(ope.at(i) == 'B') {
            if(res == "") {
                continue;
            }
            res.pop_back();
        } else {
            res.push_back(ope.at(i));
        }
    }
    cout << res << endl;
}