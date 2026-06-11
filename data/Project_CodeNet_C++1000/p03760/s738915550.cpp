#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    string O, E;
    char str[101];
    cin >> O;
    cin >> E;
    int i = 0, l;
    for (char c: O) {
        str[i] = c;
        i += 2;
    }
    str[i] = 0;
    i = 1;
    for (char c: E) {
        str[i] = c;
        i += 2;
    }
    str[i]=0;
    cout << str << endl;

}

int main() {

    solve();
    return 0;
}
