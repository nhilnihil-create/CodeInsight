#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int h, w;
    cin >> h >> w;
    char c;
    for (int i=0; i<w+2; ++i)
        cout << "#";
    cout << "\n";
    for (int i=0; i<h; ++i) {
        cout << "#";
        for (int j=0; j < w; ++j) {
            cin >> c;
            cout << c;
        }
        cout << "#\n";
    }
    for (int i=0; i<w+2; ++i)
        cout << "#";

}

int main() {

    solve();
    return 0;
}
