#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n; cin >>n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    bool ok = false;
    int odd = 0, even4 = 0, even2 = 0;

    rep(i, n) {
        if (a[i] % 2 != 0) odd++;
        else if (a[i] %4 == 0) even4++;
        else even2++;
    }
    //printf("odd=%d, even4=%d, even2=%d\n", odd, even4, even2);
    even4-=(odd-1);
    if (even4<0){
        puts("No");
        return 0;
    }
    even2 %= 2;
    if (even2 != 0) {
        if (even4!= 0)
            puts("Yes");
        else
            puts("No");
    }
    else {
        puts("Yes");
    }
}