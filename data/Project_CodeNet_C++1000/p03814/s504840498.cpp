#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

void solve() {
    int ans, a, z, i;
    char c;
    bool aFlag, bFlag;
    aFlag = bFlag = false;
    a = z = i = 0;
    while((c = getchar()) > 0) {
        if (c == 'A' && !aFlag) {
            aFlag = true;
            a = i;
        }
        if (c == 'Z') {
            z = i;
        }
        ++i;
    }
    cout << z - a + 1;

}

int main() {

    solve();
    return 0;
}
