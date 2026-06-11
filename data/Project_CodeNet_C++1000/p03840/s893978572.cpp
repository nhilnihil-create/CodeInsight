#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9;
const ll mod=998244353;
signed main(){
    ll I,O,T,J,L,S,Z;
    cin>>I>>O>>T>>J>>L>>S>>Z;
    ll ans=0;
    if(I&&J&&L){
        ll d=I%2+J%2+L%2;
        if(d>=2){
            I--;
            J--;
            L--;
            ans+=3;
        }
    }
    if(I%2)I--;
    if(J%2)J--;
    if(L%2)L--;
    ans+=I+J+L+O;
    cout<<ans<<endl;
}