#include <bits/stdc++.h>

typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define LINF 1e18
#define INF 1e9
using namespace std;

#define fs first
#define sc second
#define P pair<ll,ll>


ll n,ans,cnt;
vector<P> vec[15];
ll type[15];

int main(){
    ll n;
    cin >> n;
    ll cnt_4 = 0,cnt_2 = 0,cnt_1 = 0;
    ll a[n] = {};
    rep(i,0,n){
        cin >> a[i];
        if(a[i] % 4 == 0) cnt_4++;
        else if(a[i] % 2 == 0) cnt_2++;
        else cnt_1++;
    }

    if(cnt_1 > cnt_4+1) cout << "No" << endl;
    else if(!cnt_4 && cnt_1) cout << "No" << endl;
    else if(cnt_1 == cnt_4+1 && cnt_2) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}