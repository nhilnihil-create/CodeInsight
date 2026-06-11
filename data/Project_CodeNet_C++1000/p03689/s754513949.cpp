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
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H,W,h,w;cin>>H>>W>>h>>w;
    vector<vector<ll> >g(H,vector<ll>(W));
    if(H%h==0){
        if(W%w==0){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
            rep(i,H){
                rep(j,W){
                    ll c;
                    if(j%w==0)c=inf-w;
                    else if(j%w==w-1)c=-inf;
                    else c=1;
                    cout<<c<<' ';
                }
                cout<<endl;
            }
        }
    }else{
        cout<<"Yes"<<endl;
        rep(i,H){
            rep(j,W){
                ll c;
                if(i%h==0)c=inf-h;
                else if(i%h==h-1)c=-inf;
                else c=1;
                cout<<c<<' ';
            }
            cout<<endl;
        }
    }
}