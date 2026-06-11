#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;
  int a[n][m];
  rep(i,n) rep(j,m){
    cin >> a[i][j];
    a[i][j]--;
  }
  int ub=n;
  int lb=0;
  while(ub-lb>1){
    int	mid=(ub+lb)/2;
    set<int> unuse;
    while(1){
      int par[m];
      rep(i,m) par[i]=0;
      rep(i,n){
	rep(j,m){
	  if(unuse.count(a[i][j])==0){                                  
	    par[a[i][j]]++;
	    break;
	  }                                                             
	} 
      }
      int end=0;
      rep(i,m){
	if(par[i]>mid) unuse.insert(i);
	else end++;
      }
      if(end==m){
	ub=mid;
	break;
      }
      else if(unuse.size()==m){
	lb=mid;
	break;
      }
    }
  }
  cout << ub << endl;
  
  return 0;
    

}
