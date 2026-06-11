#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    string w;
    cin >> w;

    for (int i = 0; i < w.length(); ++i) {
        if (count(w.begin(), w.end(), w[i]) % 2 != 0) {
            cout << "No" << '\n';
            exit(0);
        }
    }

    cout << "Yes" << '\n';
    
    return 0;
}