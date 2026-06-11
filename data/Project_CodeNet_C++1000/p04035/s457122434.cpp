#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define endl "\n"
#define pll pair<ll,ll>
#define all(x) (x).begin() , (x).end()
#define f first
#define s second
#define pr(x) cout<<x<<endl;
#define pr2(x,y) cout<<x<<" "<<y<<endl;
#define pr3(x,y,z) cout<<x<<" "<<y<<endl;
#define prv(v) for(auto x:v) cout<<x<<" ";
using namespace std;
 
const ll N =(2e5+5);
const ll MOD = 1e9+7;
const ll INF = 1e16;
const ll LOG = 29;

long long binpow(long long a, long long b) {
    a%=MOD;    
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%MOD;
        a = (a * a) %MOD;

        
        b >>= 1;
    }
    res%=MOD;
    return res;
}
void solve(){
    ll n,l;
    cin>>n>>l;
    ll idx = -1;
    ll a[n+1];
    for(int i= 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i =1;i<n;i++){
        if(a[i+1]+a[i]>=l){
            idx =i;
            break;
        }

    }
    if(idx == -1){
        cout<<"Impossible\n";
        return;
    }
    cout<<"Possible\n";
    for(int i =1;i<idx;i++)cout<<i<<"\n";
    for(int i = n-1;i>idx;i--)cout<<i<<"\n";
    cout<<idx<<endl;
}

/*
1 5
2 4
2 5
2 6
3 3
3 4
3 5
3 6
3 7
4 4
4 5
4 6
5 5
*/




int main()
{
    ios_base::sync_with_stdio(0);
     cin.tie(NULL);
     
    ll t=1;
    while(t--){
        solve();
    }
     
 
 
    return 0;     
    
        
}