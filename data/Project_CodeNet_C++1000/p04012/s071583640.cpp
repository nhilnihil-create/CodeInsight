#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string w;
    cin >> w;
    vector<bool> c(26,1);
    int n = w.size();
    bool check = 1;

    for(int i = 0; i < n; i++) {
        c.at(w.at(i) - 'a') = c.at(w.at(i) - 'a')^true;
    }
    for(int i = 0; i < 26; i++) {
        if(!c.at(i)) {
            check = 0;
        }
    }
    if(check) {
    cout << "Yes" << endl;
    } else {
    cout << "No" << endl;
    }

    return 0;
}