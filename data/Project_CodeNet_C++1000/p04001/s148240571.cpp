#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
    string s;
    cin >> s;
    __int64_t ans = 0;
    for(int i = 0; i < (1 << static_cast<int>(s.size() - 1)); i++){
        __int64_t x = s.at(0) - '0';
        for(int j = 0; j < static_cast<int>(s.size() - 1);j++){
            if(i & (1 << j)){
                ans += x;
                x = 0;
            }
            x = 10 * x + (s.at(j + 1) - '0');
        }
        ans += x;
    }
    cout << ans << endl;
    return 0;
}

