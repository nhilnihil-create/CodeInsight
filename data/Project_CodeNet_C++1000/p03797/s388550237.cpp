#include <bits/stdc++.h>

using namespace std;

#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define f first
#define se second
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))

typedef long long ll;
//#define MOD 1000000007

void solve()
{
    ll n,m;
    cin>>n>>m;
    if(n*2>=m){
        ll ans=m/2;
        cout<<ans<<endl;
    }
    else{
        if(2*n==m){
            cout<<n<<endl;
        }
        else{
            ll totalC=(2*n)+m;
            ll ans=totalC/4;
            cout<<ans<<endl;
        }
    }
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
