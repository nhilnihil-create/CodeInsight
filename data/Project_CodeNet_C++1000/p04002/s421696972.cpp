#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=1e9+7;
int dx[]={-1,-1,-1,0,0,0,1,1,1};
int dy[]={-1,0,1,-1,0,1,-1,0,1};
int main(){
    vector<pii>ab(0);
    ll h,w,n;cin>>h>>w>>n;
    rep(i,n){
        int a,b;cin>>a>>b;
        rep(j,9){
            if(a+dx[j]>=2&&b+dy[j]>=2&&a+dx[j]<h&&b+dy[j]<w)
            ab.pb(make_pair(a+dx[j],b+dy[j]));
        }
    }
    sort(all(ab));
    ab.pb(make_pair(0,0));
    vector<ll>j(10);
    ll cnt=1,cntall=0;
    REP(i,1,ab.size()){
        if(ab[i]==ab[i-1]){
            cnt++;
        }else{
            j[cnt]++;
            cnt=1;
            cntall++;
        }
    }
    j[0]=(h-2)*(w-2)-cntall;
    rep(i,10)cout<<j[i]<<endl;
}