#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define endl '\n'

signed main() {
    int n,m;
    cin >> n >> m;

    map<int,int> mp;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        mp[a]++;
        mp[b]++;
    }

    bool flag = true;
    for(auto it : mp){
        if(it.second % 2 != 0) flag = false;
    }
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}