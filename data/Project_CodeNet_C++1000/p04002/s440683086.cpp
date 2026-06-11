#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e9+7;

ll h, w, n, ans[10];
set<pair<ll,ll>> s;

int main () {
    cin >> h >> w >> n;
    ans[0] = (h-2)*(w-2);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        for (int ai = a-1; ai <= a+1; ai++) {
            if (ai <= 1 || ai >= h) continue;
            for (int bi = b-1; bi <= b+1; bi++) {
                if (bi <= 1 || bi >= w) continue;
                ll temp = 0;
                for (int j = ai-1; j <= ai+1; j++)
                    for (int k = bi-1; k <= bi+1; k++) 
                        if (s.count({j,k}))
                            temp++;
                ans[temp]--;
                ans[temp+1]++;
            }
        }
        s.insert({a,b});
    }
    for (int i = 0; i < 10; i++) cout << ans[i] << endl;
    return 0;
}