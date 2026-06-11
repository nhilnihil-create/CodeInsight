#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1000000010
#define EPS 1e-9
#define fst first
#define scd second

#define debug(x) cout<<x<<endl;
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define lp(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
#define int long long
#define endl "\n"


signed main(){
  cin.tie(0);	
  ios::sync_with_stdio(false);
  int n,x;
  cin>>n>>x;
  if(x==1 || x==2*n-1) cout<<"No"<<endl;
  else{
    int a[200000]={0};
    rep(i,200000){
      a[i]=i+1;
    }
    if(n>2){
      if(x==2){
	swap(a[n-1],a[1]);
	swap(a[n],a[0]);
      }else{
	bool flag[200001]={false};
	a[n-2]=x-2;
	a[n-1]=x;
	a[n]=x+1;
	a[n+1]=x-1;
	flag[n-2]=flag[n-1]=flag[n]=flag[n+1]=true;
	int now=0,nex=1;
	while(now<n*2-1){
	  if(nex>=x-2 && nex<=x+1) nex++;
	  else if(flag[now]) now++;
	  else if(!flag[now]){
	    a[now]=nex;
	    now++;
	    nex++;
	  }
	}
      }
    }
    cout<<"Yes"<<endl;
    rep(i,n*2-1){
      cout<<a[i]<<endl;
    }
  }
  return 0;
}
