#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    string gr, ls, eq;
    gr = "GREATER"; ls = "LESS"; eq = "EQUAL";
    string A, B;
    cin >> A; cin >> B;
    if (A.size() > B.size())
        cout << gr;
    else if (A.size() < B.size())
        cout << ls;
    else {
        if (A < B)
            cout << ls;
        else if (A > B)
            cout << gr;
        else
            cout << eq;
    }

}

int main() {

    solve();
    return 0;
}
