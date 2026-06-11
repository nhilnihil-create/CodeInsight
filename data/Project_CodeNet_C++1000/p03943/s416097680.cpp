#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

int main() {
    int candies[3];
    rep(0, 3) cin >> candies[i];

    bool found = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (i != j && i!=k && j != k) {
                    if (candies[i] + candies[j] == candies[k]) {
                        found = true;
                        break;
                    }
                }
            }
        }
    }

    cout << (found ? "Yes" : "No") << endl;

    return 0;
}
