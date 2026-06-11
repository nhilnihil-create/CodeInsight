#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 1;
    cin >> n;
    int a[n];
    
    for(int i = 0 ; i < n; ++i) cin >> a[i];
    int flag = 0; // 1:up, -1:down
    for(int i = 0; i < n-1; ++i) {

        if(a[i] > a[i+1]) { // down
            if(flag == 1) {
                ans++;
                flag = 0;
            } else {
                flag = -1;
            }
        } else if(a[i] < a[i+1]) { // up
            if(flag == -1) {
                ans++;
                flag = 0;
            } else {
                flag = 1;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
