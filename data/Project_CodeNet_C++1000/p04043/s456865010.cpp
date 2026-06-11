#include <bits/stdc++.h>
using namespace std;

int main() {
    int temp, cnt5=0, cnt7=0;

    for (int i = 0 ; i < 3 ; ++i) {
        cin >> temp;
        if (temp == 5) cnt5++;
        if (temp == 7) cnt7++;
    }

    cout << (cnt5 == 2 && cnt7 == 1 ? "YES" : "NO");

    return 0;
}
