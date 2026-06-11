#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const int INF=2e9;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    int n,m,k;
    cin >> n >> m >> k;
    bool flag=0;
    rep(i,n+1) {
        rep(j,m+1) {
            int b=m*i+n*j-2*i*j;
            if (b==k) flag=1;
        }
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
   
    return 0;  
}