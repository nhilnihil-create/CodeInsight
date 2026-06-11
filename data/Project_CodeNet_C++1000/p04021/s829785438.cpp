#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=1e9+7;
int main(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    map<ll,ll>m;
    rep(i,n){
        cin>>a[i];
        m[a[i]]=i;
    }
    ll cnt=0;
    sort(all(a));
    rep(i,n){
        if(i%2!=m[a[i]]%2)cnt++;
    }
    cout<<cnt/2<<endl;
}