#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    string w;
    cin >> w;
    int size = w.size();
    map<char, int>d;
    for (int i=0; i<size; i++) {
        if (d.count(w[i]) > 0) {
            d[w[i]] = d[w[i]] + 1;
        } else {
            d[w[i]] = 1;
        }
    }

    bool beautiful = true;
    for (auto c : d) {
        if (c.second % 2 != 0) {
            beautiful = false;
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