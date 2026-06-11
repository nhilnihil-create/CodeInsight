#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n+1];
    bool pressed[n+1] = {};
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    int on = 1, cnt = 0;
    while (on != 2) {
        if (pressed[a[on]] == false) {
            pressed[a[on]] = true;
            on = a[on];
            cnt++;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << cnt << endl;
}