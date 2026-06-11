#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int cnt = 0;
    while (cnt * (cnt + 1) / 2 < n) cnt++;
    cout << cnt;
    return 0;
}
