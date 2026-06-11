#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    if (n == 2) {
        if (x == 2) cout << "Yes\n1\n2\n3\n";
        else cout << "No\n";
    } else if (x == 1 || x == 2*n-1)
        cout << "No\n";
    else {
        vector<int> ans(2*n-1);
        ans[n-1] = x;
        ans[n-2] = x-1;
        ans[n] = x+1;
        if (x >= 3) ans[n+1] = x-2;
        if (x < 2*n-2) ans[n-3] = x+2;
        for (int i = 1, j = 0; i <= 2*n-1; i++)
            if (abs(i - x) > 2) {
                while (ans[j] > 0) j++;
                ans[j] = i;
            }
        cout << "Yes\n";
        for (int a : ans) cout << a << endl;
    }
}
