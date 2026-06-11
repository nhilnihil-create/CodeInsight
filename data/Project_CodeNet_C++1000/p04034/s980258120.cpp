#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x, y;
    cin >> n >> m;
    vector<int> num(n, 1);
    int red[n] = {0};
    red[0] = 1;
    for(int i = 0; i < m; ++i) {
        cin >> x >> y;
        x--, y--;
        if(red[x] == 1) {
            num[x]--;
            num[y]++;
            red[y] = 1;
            if(num[x] == 0) {
                red[x] = 0;  
            }
        } else {
            num[x]--;
            num[y]++;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        ans += red[i]; 
    }

    cout << ans << '\n';
    
    return 0;
}
