#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;

    int rate[8];
    for (int i = 0; i < 8; i++)
    {
        rate[i] = 0;
    }

    int up = 0;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        if (a >= 3200) up++;
        else rate[a/400]++;
    }
    int ans1 = 0;
    for (int i = 0; i < 8; i++) {
        if (rate[i] > 0) ans1++;
    }
    int ans2 = ans1;
    if (up > 0) ans2 += up;
    if (ans1==0) ans1++;
    cout << ans1 << " " << ans2 << endl;

  return 0;
}
