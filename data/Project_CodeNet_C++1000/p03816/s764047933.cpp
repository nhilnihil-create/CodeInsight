#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(100'000, 0);
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x; x--;
        a[x]++;
    }
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < 100'000; i++){
        if (a[i] >= 3) a[i] = 2 - (a[i] % 2);
    }
    for (int i = 0; i < 100'000; i++){
        if (a[i] > 0) ans++;
        if (a[i] > 1) cnt++;
    }
    cout << ans - (cnt % 2) << endl;
}