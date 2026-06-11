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
    ll n;cin>>n;
    vector<vector<ll> >a(n,vector<ll>(n));
    ll sum=0;
    bool f=1;
    rep(i,n)rep(j,n){
        cin>>a[i][j];
        sum+=a[i][j];
    }
    sum/=2;
    rep(i,n-1){
        REP(j,i+1,n){
            rep(k,n){
                if(k!=i&&k!=j){
                    if(a[i][k]+a[k][j]<a[i][j]){
                        f=0;
                    }
                    if(a[i][k]+a[k][j]==a[i][j]){
                        sum-=a[i][j];
                        break;
                    }
                }
                if(!f)break;
            }
            if(!f)break;
        }
        if(!f)break;
    }
    cout<<(f?sum:-1)<<endl;
}