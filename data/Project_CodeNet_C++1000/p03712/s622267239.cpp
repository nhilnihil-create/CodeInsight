
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int h, w;
char t;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> h >> w;
    for (int i = 0; i < w + 2; ++i) {
        cout << "#";
    }
    cout << endl;
    for (int i = 0; i < h; ++i) {
        cout << "#";
        for (int j = 0; j < w; ++j) {
            cin >> t;
            cout << t;
        }
        cout << "#" << endl;
    }
    for (int i = 0; i < w + 2; ++i) {
        cout << "#";
    }
    cout << endl;

    return 0;
}

