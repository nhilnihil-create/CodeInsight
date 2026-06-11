#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;


int main(void){
        int N, P;
        cin >> N >> P;
        ll ans = 1;
        int a[2] = {0,0};
        rep(i,N) {
                int A;
                cin >> A;
                a[A%2]++;
                ans *= 2;
        }

        if (a[1] == 0) {
                if ( P == 1) ans = 0;
        }
        else ans /= 2;

        cout << ans << endl;
        return 0;
}