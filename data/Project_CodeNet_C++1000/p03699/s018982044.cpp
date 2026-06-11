#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i, 0, n) cin >> s[i];
    vector<int> a;
    int ans = 0;
    rep(i, 0, n){
        ans += s[i];
        if(s[i]%10) a.push_back(s[i]);
    }
    if(ans%10) cout << ans << endl;
    else{
        if(a.size() == 0) cout << 0 << endl;
        else{
            sort(a.begin(), a.end());
            cout << ans - a[0] << endl;
        }
    }
    return 0;
}
