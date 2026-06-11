#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k = 0, s = 0;
    cin >> k >> s;

    int ans = 0;
    for(int i = 0; i <= k; i++) {
        for(int j = 0; j <= k; j++) {
            if(i + j <= s && (s - (i + j) <= k)) ans++; 
        }
    }

    cout << ans << endl;


    return 0;
}