#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;


int main(void){
        int N, P;
        cin >> N >> P;
        int a[2] = {0,0};
        rep(i,N) {
                int A;
                cin >> A;
                a[A%2]++;
        }

        ll ans = 1;
        if (a[1] == 0) {
                if ( P == 0) rep(i,N) ans *= 2;
                else ans = 0;
        }
        else rep(i,N-1) ans *= 2;

        cout << ans << endl;
        return 0;
}