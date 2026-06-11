#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll>

using namespace :: std;

const ll maxn=110;
const ll maxk=22;
const ll mod=1e9+7;
const ll inf=1e9+500;

struct hh{
    vector<ll> sar;
    vector<ll> tah;
    ll maxx;
};
hh f(ll n){
    hh ans;
    if(n==2){
        ans.sar.pb(1);
        ans.tah.pb(1);
        ans.maxx=1;
        return ans;
    }
    if(n%2==0){
        ans=f(n/2);
        ans.sar.pb(ans.maxx+1);
        ans.tah.pb(ans.maxx+1);
        ans.maxx++;
        return ans;
    }
    ans=f(n-1);
    ans.sar.pb(ans.maxx+1);
    ans.tah.pb(ans.maxx+1);
    for(ll i=ans.tah.size()-1;i>=1;i--){
        swap(ans.tah[i],ans.tah[i-1]);
    }
    ans.maxx++;
    return ans;
}
int main(){
    string s,t;
    ll n;
    cin>>n;
    n++;
    hh e=f(n);
    cout<<e.sar.size()+e.tah.size()<<endl;
    for(auto v:e.sar){
        cout<<v<<' ';
    }
    for(auto v:e.tah){
        cout<<v<<' ';
    }
}

