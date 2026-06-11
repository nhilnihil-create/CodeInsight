#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main(){
    int k, n;
    cin >> n >> k;
    vector<int> l(n);
    for(int i = 0; i < n; i++){
        cin >> l[i];
    }

    sort(l.begin(), l.end());

    int ans = 0;
    for(auto i = l.rbegin(); i < l.rbegin() + k; i++){
        ans += *i;
    }

    cout << ans << endl;
    return 0;
}