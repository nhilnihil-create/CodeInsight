#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,s,e) for(int i = s; i < e; ++i)
#define rep2(i,s,e) for(int i = s; i < e; ++i)  
#define rep_1(i,s,e) for(int i = s; i >= 0; --i)
#define ll long long
#define ull unsigned long long
#define vi vector< int >
#define vvi vector< vector< int > >
#define pii pair< int,int >
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fastio cin.tie(0),cout.tie(0);ios::sync_with_stdio(0);
using namespace std;

int main(){

  fastio
  string n; 
  int k; cin >> n >> k;
  bool arr[10]; 
  memset(arr,1,sizeof(arr));
  int x;
  rep(i,k){
  	cin >> x;
  	arr[x] = false;
  }
  vector< char > valid;
  rep(i,10){
  	if(arr[i]){
      valid.pb(i + '0');
  	}
  }
  vi pos;
  rep(i,(int)n.length()){
  	if(!arr[n[i] - '0']) pos.pb(i);
  }
  int len = (int)n.length();
  string ans = "";
  if(!pos.size()){cout << n << '\n';
   return 0;
  }
  else if(pos[0] == 0){
  	auto z = upper_bound(all(valid),n[pos[0]]);
  	if(z == valid.end()){
  		if(valid[0] == '0'){
  			ans += valid[1];
  			ans += valid[0];
  			rep(i,len - 1) ans += valid[0];
  		}
  		else{
  			ans += valid[0];
  			ans += valid[0];
  			rep(i,len - 1) ans += valid[0];
  		}
  	}
  	else{
  			ans = *z + ans;
  			rep(i,len - 1) ans += valid[0];
  	}
  	cout << ans << '\n';
  }
  else{
  	//cout << pos[0] << '\n';
  	auto z = upper_bound(all(valid),n[pos[0]]);
  	if(z == valid.end()){
  		rep(i,len - pos[0]) ans += valid[0];
  		bool flag = true;
  		for(int i = pos[0] - 1; i >= 0; --i){
  			auto p = upper_bound(all(valid),n[i]);
  			if(flag && p == valid.end()){
  				ans = valid[0] + ans;
  			}
  			else if(flag && !(p == valid.end())){
  				ans = *p + ans;
  				flag = false;
  			}
  			else ans = n[i] + ans;
  		}
  		if(ans.length() == n.length()){
  			if(ans < n){
  				ans = (valid[0] == '0'?valid[1]:valid[0]) + ans;
  			}
  		}
  	}
  	else{
  		ans += *z;
  		rep(i, len - pos[0] - 1) ans += valid[0];
  		for(int i = pos[0] - 1; i >= 0; --i){
  			ans = n[i] + ans;
  		}
  	}
  	cout << ans << '\n';
  }
	return 0;
} 
