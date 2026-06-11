#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n, m, ans = 0;
    cin >> n >> m;
    if(m < 2)cout << 0;
    else{
        if(m >= 2 * n){
            ans += n;
            m = m - n * 2;
            if(m >= 4){
                ans += m / 4;
            }
            cout << ans;
        }else cout << m / 2;
    }
    return 0;
}
