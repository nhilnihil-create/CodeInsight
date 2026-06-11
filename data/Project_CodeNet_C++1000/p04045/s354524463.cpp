#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=998244353;
const ll INF=2e15;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false); 

    ll n,k;
    cin >> n >> k;
    vector<int> d(k);
    rep(i,k) cin >> d[i];
    sort(d.begin(),d.end());
    int ans=0;
    repr(i,n,n+1000000) {
        bool flag=1; 
        int j=i;
        while (j>0) {
            int l=j%10;
            bool okay=1;
            rep(m,k) {
                if (l==d[m]) okay=0;
            }
            if (!okay) {
                flag=0;
                break;
            }
            j/=10;
        }
        if (flag) {
            ans=i;
            break;
        }
    }
    cout << ans << endl;


    return 0;
}
