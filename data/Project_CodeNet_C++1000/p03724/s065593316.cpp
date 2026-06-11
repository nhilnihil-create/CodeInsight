#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
const int MOD=1e9+7;



int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<int> t(n);
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        ++t[a-1];
        ++t[b-1];
    }
    bool flag=1;
    rep(i,n) {
        if (t[i]%2==1) flag=0;
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;   
}
