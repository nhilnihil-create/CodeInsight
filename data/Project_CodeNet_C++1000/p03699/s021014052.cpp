#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define rREP(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    

    int n;
    cin >> n;
    int ary[n];
    rep(i,n) cin >> ary[i];

    int sum = 0;
    int non_zero_itr = -1;
    sort(ary, ary+n);
    rep(i,n)
    {
        if(ary[i]%10!=0)
        {
            non_zero_itr = i;
            break;
        }
    }
    rep(i,n) sum += ary[i];

    if (sum%10==0)
    {

        if (non_zero_itr==-1)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << sum - ary[non_zero_itr] << endl;
        }
        
    }
    else
    {
        cout << sum << endl;
    }
}
