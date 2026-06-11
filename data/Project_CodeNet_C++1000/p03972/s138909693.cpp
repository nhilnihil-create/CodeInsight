#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int main(){
    ll w,h,p,q;
    cin>>w>>h;
    vector<pair<int,int>> A;
    rep(i,w) cin>>p,A.push_back(make_pair(p,0));
    rep(i,h) cin>>q,A.push_back(make_pair(q,1));
    sort(A.begin(),A.end());
    ll ans=0,W=w+1,H=h+1;
    rep(i,w+h){
        if(A[i].second==0) ans+=A[i].first*H,W--;
        else ans+=A[i].first*W,H--;
    }
    cout<<ans;
}