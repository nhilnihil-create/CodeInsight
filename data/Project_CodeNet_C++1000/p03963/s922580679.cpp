
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int n, k;
    cin >> n >> k;
    int ans = 1;
    if (n == 1){
        cout << k << endl;
    }
    else{
        ans *= k;
        for (int i = 0; i < n - 1; i++ ){
            ans *= (k - 1);
        }
        cout << ans << endl;

    }

    
}