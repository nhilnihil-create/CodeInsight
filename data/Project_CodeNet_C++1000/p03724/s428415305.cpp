#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
int main()
{
    int n,m;
    cin >> n >> m;
    map<int,int> mp;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        mp[a]++;mp[b]++;
    }
    bool ok = true;
    rep(i,n){
        if(mp[i]%2){
            ok = false;
            break;
        }

    }
    if(ok)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}