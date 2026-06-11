#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int a,b,c;
    cin >> a >> b >> c;
    long long t = 0;
    for (long long  i=1; i <= b; ++i) {
        t +=a ;
        if (t % b == c) {
            cout << "YES";
            return;
        }
    }
    cout << "NO";

}

int main() {

    solve();
    return 0;
}
