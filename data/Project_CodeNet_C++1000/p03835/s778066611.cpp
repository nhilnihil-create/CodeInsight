#include <iostream>
using namespace std;

int main() {
    int k, s;
    cin >> k >> s;
    int count = 0;
    for (int x = 0; x <= k; x++) {
        if (x > s) continue;
        int ypz = s - x;
        if (ypz < k)
            count += (ypz + 1);
        else if (ypz >= k && ypz <= 2 * k)
            count += (k - (ypz - k) + 1);
        else
            count += 0;
    }
    cout << count << endl;
    return 0;
}