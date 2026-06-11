#include <iostream>

using namespace std;

int main(void) {
    int64_t x;
    cin >> x;
    int64_t ans = (x+10)/11 * 2;
    if(0 < x%11 && x%11 <= 6) {
        ans--;
    }
    cout << ans << endl;
    return 0;
}
