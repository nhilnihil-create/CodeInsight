#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n, greater<int>());
    int i = 0;
    while (i < n && i < a[i]) i++;
    i--;
    bool up = a[i] > i + 1, right = (i < n - 1 && a[i + 1] == i + 1);
    if (up && (a[i] - i) % 2 == 0) { cout << "First\n"; return 0; }
    if (right) {
        int j = i;
        while (j < n-1 && a[j+1] == i+1) j++;
        if ((j - i) % 2 == 1) { cout << "First\n"; return 0; }
    }
    cout << "Second\n";
}
