#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string w;
    cin >> w;

    vector<int> ab(26);
    char cbuff;
    rep(i,w.size()) {
        ab.at(w.at(i)-'a')++;
    }

    bool beautiful=true;
    rep(i,ab.size()) {
        if (ab.at(i)%2) {
            beautiful=false;
            break;
        }
    }

    if (beautiful) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}