#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
#define pb push_back
#define mp make_pair
#define fr(i,n) for(int i=0;i<n;i++)
#define Fr(i,n) for(int i=0;i++<n;)
#define ifr(i,n) for(int i=n-1;i>=0;i--)
#define iFr(i,n) for(int i=n;i>0;i--)
#define srd(i,x) for(int i=x-1;i<=x+1;i++)

int main(){
  ll h,w,n,a[100010],b[100010],c,ans[10]={};
  map<P,bool> m,vis;
  cin>>h>>w>>n;
  fr(i,n){
    cin>>a[i]>>b[i];
    m[mp(--a[i],--b[i])]=1;
  }
  fr(k,n){
    srd(i,a[k]){srd(j,b[k]){if(0<i&&i<h-1&&0<j&&j<w-1){
      if(!vis[mp(i,j)]){
        vis[mp(i,j)]=1;
        c=0;
        srd(I,i) srd(J,j) c+=m[mp(I,J)];
        ans[c]++;
      }
    }}}
  }
  ans[0]=(h-2)*(w-2);
  Fr(i,9) ans[0]-=ans[i];
  fr(i,10) cout<<ans[i]<<endl;
}