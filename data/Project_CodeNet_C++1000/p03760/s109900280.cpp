#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string O, E, ans = ""; cin >> O >> E;
    int e = E.length(), j = 0, k = 0;
    for (int i = 0; i < 2 * O.length(); ++i) {
        if (i % 2 == 0) {
            ans += O[j];
            j++;
        }
        else if (e >= 1){
            ans += E[k];
            e--, k++;
        }
    }
    cout << ans << endl;
}
