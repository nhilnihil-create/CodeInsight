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

  int n,x;
  vector<int> ans;
  cin >> n >> x;
  if(x==1 || x==2*n-1) cout << "No" << endl;
  else{
    cout <<"Yes" << endl;
    if(x==2){
    
      rep1(i,2*n-1){
	if(i!=x-1 && i!= x && i!= x+1 && i!=x+2){
	  ans.pb(i);
	}
	if(ans.size()==n-2){
	  ans.pb(x+1);
	  ans.pb(x);
	  ans.pb(x-1);
	  ans.pb(x+2);
	}
      }
    }
    else{
      rep1(i,2*n-1){
        if(i!=x-1 && i!= x && i!= x+1 && i!=x-2){
          ans.pb(i);
	}
	if(ans.size()==n-2){
          ans.pb(x-1);
          ans.pb(x);
          ans.pb(x+1);
          ans.pb(x-2);
	}
      }
    }
    rep(i,2*n-1) cout << ans[i] << endl;
  }
    

  
  return 0;
    

}
