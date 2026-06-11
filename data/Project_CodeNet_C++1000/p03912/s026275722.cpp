#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define per1(i,n) for(int i=n;i>0;i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll num[200001],numm[200001][2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,X[200001];
    cin>>n>>m;
    rep(i,n) cin>>X[i],num[X[i]]++,numm[X[i]%m][0]++;
    rep1(i,100001) numm[i%m][1]+=num[i]/2*2;
    ll ans=0;
    rep(i,m/2+1){
        if(i==0||i==m-i) ans+=numm[i][0]/2;
        else{
            if(numm[i][0]>numm[m-i][0]) swap(numm[i],numm[m-i]);
            ans+=numm[i][0];
            numm[m-i][0]-=numm[i][0];
            if(numm[m-i][0]<numm[m-i][1]) ans+=numm[m-i][0]/2;
            else ans+=numm[m-i][1]/2;
        }
    }
    cout<<ans;
}