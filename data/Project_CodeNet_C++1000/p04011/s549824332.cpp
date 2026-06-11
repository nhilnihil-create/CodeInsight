#include <iostream>
using namespace std;

int main() {
    int n, k, x, y;
    int cost;
    cin >> n >> k >> x >> y;
    if (n > k)
        cost = x * k + y * (n - k);
    else
        cost = x * n;

    cout << cost << endl;
    return 0;
}
