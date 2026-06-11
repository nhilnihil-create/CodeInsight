#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int, int >
#define F first
#define S second
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
/// khodaya komak kon
/// ya navid navid
/// ye tec khaphan ke yadam bemone : age jayi didi soale masir hamiltoni mikhad rasasho bokon yal oilery;
/// age ye ja mikhasti to dp az ozv i k ta entekhab koni bejash ye log bezan (nominal) hamoon 2**k va o 1 ent kon

///\\\///\\\///\\\\\\\\\\\\\\\\\///\\\///\\\///

const int N=2e5,mod=1e9+7;
ll a[N];

int32_t main(){
    vector <int> b;
    ll n;
    cin >> n;
    ll ans=0;
    for (int i=0;i<n;i++){
        cin >> a[i];
        if (a[i]==i+1){
            b.pb(i-1);
        }

    }
    //cout << b.size() << endl;
    for (int i=0;i<b.size();i++){
        ll k=i;

        while (k+1<b.size() && b[k+1]-1==b[k]){
            k++;
        }

        ans+=(k-i+2)/2;
        i=k;
    }
    cout << ans;
}














