#include <bits/stdc++.h>
using namespace std;

int main() {
    string N;
    cin >> N;
    for (int i=0; i<int(N.size()); i++) {
        if (N.at(i)=='9') {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}