#include "bits/stdc++.h"
using namespace std;


int main() {
    string a, b, c;
    cin >> a >> b >> c;
    int aa = a.size();

    int bb = b.size();

    int cc = c.size();

    if (a.at(aa - 1) == b.at(0) && b.at(bb - 1) == c.at(0)) {
        cout << "YES" << endl;
    }

    else {
        cout << "NO" << endl;
    }

}

