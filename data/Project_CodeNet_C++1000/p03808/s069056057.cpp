#include <bits/stdc++.h>
#define pb push_back
#define REP(i, n) for (signed long long i = 0; i < (n); i++)
#define MOD 1000000007
#define bitcnt(a) (ll) __builtin_popcount((a))
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main() {
    ll n,all=0;
    vector<ll>v;
    cin>>n;
    REP(i,n){
        ll p;
        cin>>p;
        all+=p;
        v.pb(p);
    }

    ll oneCnt=(1+n)*n/2;
    if(all%oneCnt){
        cout<<"NO"<<endl;
        return 0;
    }
    ll times = all/oneCnt;
    REP(i,n){
        ll dif=v[(i+1)%n]-v[i];
        if(dif>times||(dif-times)%(n)){
            cout<<"NO"<<endl;
            return 0;
        }
    }  
    cout<<"YES"<<endl;

}
