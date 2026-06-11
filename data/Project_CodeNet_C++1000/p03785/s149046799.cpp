#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
using namespace std;
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n,c,k;
  cin >> n >> c >> k;
  
  vector<int> t(n);
  rep(i,n) cin >> t[i];
  sort( t.begin(), t.end() );
  
  int cnt = 0;
  int num = 0, t_max = -1;
  rep(i,n){
    if(t[i] > t_max || num == c){
      cnt++; 
      num = 1; t_max = t[i] + k;
    }else{
      num++;
    }
  }
  
  cout << cnt << endl;
  
  return 0;
}
