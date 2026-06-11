#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int a[100010];
    cin >> n;
//奇数の数をカウントし偶数個ならYESと出力するだけ！
    int odd = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 1) odd++;
    }
    if (odd % 2 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}