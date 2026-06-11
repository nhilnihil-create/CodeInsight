#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector a(n+1,0);
    for (int i=0; i<n; i++) cin >> a[i];
    long ans = 0;
    for (int i=0; i<n; i++) {
        if (a[i]%2 && a[i+1]) ans++,a[i+1]--;
        ans += a[i] / 2;
        a[i] %= 2;
    }


    cout << ans << endl;
}
