#include <bits/stdc++.h>
using namespace std;

int main() {
    string O, E; cin >> O >> E;
    vector<char> ans;
    for (int i = 0; i < O.size(); i++) {
        ans.push_back(O.at(i));
        if (i == O.size()-1 && O.size() != E.size()) {
            break;
        }
        ans.push_back(E.at(i));
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans.at(i);
    }
    cout << endl;
}