#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i, n) for(int i=0; i<(int) n; i++)

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    int odd = 0;

    rep(i, n) {
        int ai;
        cin >> ai;

        if (ai % 2 != 0) {
            odd++;
        }
    }

    if (odd % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}