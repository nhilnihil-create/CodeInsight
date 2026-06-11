#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
#define pb push_back
#define ft first
#define sd second
#define mp make_pair
#define fr(i,n) for(int i=0;i<n;i++)
#define Fr(i,n) for(int i=0;i++<n;)
#define ifr(i,n) for(int i=n-1;i>=0;i--)
#define iFr(i,n) for(int i=n;i>0;i--)

int main(){
  ll w,h,p,c[2]={},ans=0;
  pair<ll,bool> lb[200010];
  cin>>w>>h;
  fr(i,w){cin>>p;lb[i]=mp(p,0);}
  fr(i,h){cin>>p;lb[w+i]=mp(p,1);}
  sort(lb,lb+h+w);
  fr(i,h+w){
    if(lb[i].sd){
      c[1]++;
      ans+=(w+1-c[0])*lb[i].ft;
    }
    else{
      c[0]++;
      ans+=(h+1-c[1])*lb[i].ft;
    }
  }
  cout<<ans<<endl;
}