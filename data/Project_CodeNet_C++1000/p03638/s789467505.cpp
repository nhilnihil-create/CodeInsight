#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    ll h,w,n;
    cin>>h>>w>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    vector<vector<ll>> board(h,vector<ll>(w,0));
    pair<ll,ll> nowc=make_pair(0,0);
    ll nowi=0,cnt=0;
    while(nowc.second<h){
        board[nowc.second][nowc.first]=nowi+1;
        cnt++;
        if(cnt==a[nowi]){
            nowi++;
            cnt=0;
        }
        if(w==1) nowc.second++;
        else if(nowc.first==w-1){
            if(nowc.second%2) nowc.first--;
            else nowc.second++;
        }else if(nowc.first==0){
            if(nowc.second%2) nowc.second++;
            else nowc.first++;
        }else{
            if(nowc.second%2) nowc.first--;

            else nowc.first++;
        }
    }
    rep(i,h){
        rep(j,w) cout<<board[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}