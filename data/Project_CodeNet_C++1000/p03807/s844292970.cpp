#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    int count = 0;
    for (auto i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] % 2) count++;
    }
    if(count % 2 == 0) {
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;
    return 0;
}