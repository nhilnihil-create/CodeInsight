#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);


int main(void)
{
    string s; cin>>s;
    ll n=s.size();
    set<char> st;
    rep(i,n){
        st.insert(s[i]);
    }
    bool ok=false;
    vector<ll> a(4,0);
    if(st.size()==4) ok=true;
    if(st.size()==2){
        for(auto x:st){
            if(x=='N') a[0]++;
            if(x=='S') a[1]++;
            if(x=='E') a[2]++;
            if(x=='W') a[3]++;
        }
        if(a[0]>0 && a[1]>0 && a[2]==0 && a[3]==0) ok=true;
        if(a[2]>0 && a[3]>0 && a[0]==0 && a[1]==0) ok=true;
    }
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
    return 0;
}