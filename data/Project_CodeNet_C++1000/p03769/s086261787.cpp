#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
VVI ncr;
vector<pair<in,VI> > w;
void genw(){
  VI aw(200);
  for(in i=2;i<sz(aw);++i){
    in tw=0;
    for(in s=2;s<=i;s+=2){
      tw+=ncr[i][s];
      tw=min(tw,in(1e13));
    }
    aw[i]=tw;
    if(tw<1e13)
      w.PB(MP(tw,VI(i,0)));
  }
  VI vr;
  for(in a=1;a<=30;++a){
    for(in b=1;b<=30;++b){
      for(in c=1;c<=30;++c){
	for(in d=1;d<=30;++d){
	  in tw=aw[a+c]+aw[b+d];
	  if(tw>1e13)
	    continue;
	  bool ok=1;
	  for(in i=1;i<=min(a,c);++i){
	    if(!ok)
	      break;
	    for(in j=1;j<=min(b,d);++j){
	      if(double(ncr[a][i])*ncr[b][j]*ncr[c][i]*ncr[d][j]>1e13){
		ok=0;
		break;
	      }
	      tw+=ncr[a][i]*ncr[b][j]*ncr[c][i]*ncr[d][j];
	    }
	  }
	  if(!ok)
	    continue;
	  if(tw>=1e13)
	    continue;
	  vr.clear();
	  forn(x,a)
	    vr.PB(0);
	  forn(x,b)
	    vr.PB(1);
	  forn(x,c)
	    vr.PB(0);
	  forn(x,d)
	    vr.PB(1);
	  w.PB(MP(tw,vr));
	}
      }
    }
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  w.resize(209);
  ncr.resize(209,VI(209));
  forv(i,ncr){
    ncr[i][i]=ncr[i][0]=1;
    for(in j=1;j<i;++j){
      ncr[i][j]=min(in(1e13),ncr[i-1][j-1]+ncr[i-1][j]);
    }
  }
  VI ans;
  in nxt=1;
  genw();
  sort(all(w));
  reverse(all(w));
  in mw;
  forv(i,w){
    if(w[i].first==0)
      continue;
    if(w[i].first>n)
      continue;
    n-=w[i].first;
    mw=0;
    forv(j,w[i].second){
      mw=max(mw,w[i].second[j]);
      ans.PB(nxt+w[i].second[j]);
    }
    nxt+=mw+1;
    --i;
  }
  cout<<sz(ans)<<endl;
  forv(i,ans)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}
