#include <bits/stdc++.h>

using namespace std;


int main() {
    int n , s ; cin  >> n >> s;
    int ans = 0;
    for(int i = 0; i <=n; ++i){
        for(int j = 0; j  <= n; ++j){
            if(s - (i + j) >= 0 && s - (i + j) <= n)ans++;
        }
    }
    cout << ans << endl;
    
}