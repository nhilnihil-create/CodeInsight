#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    char c;
    int i = 1;
    while ((c = getchar()) != '\n') {
        if (i&1)
            cout << c;
        i ^=1;
    }

}

int main() {

	solve();
    return 0;
}
