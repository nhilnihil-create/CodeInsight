#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N, x, ans = 0, i, baki, khabo, s, r;
    cin >> N >> x;
    long long a[N];
    for(i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(i = 1; i < N; i++) {
        if(a[i] + a[i-1] > x) {
            s = a[i] + a[i-1];
            r = s - x;
            ans+= r;
            khabo = min(a[i], r);
            a[i]-= khabo;
//            r-= khabo;
//            if(r > 0) {
//               a[i-1]-= r;
//            }
        }
    }
    cout << ans;
}
