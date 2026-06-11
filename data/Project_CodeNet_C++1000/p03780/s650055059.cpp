#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

bool need(vector<int> &a, int &cn, int &k){
  if(k<=a[cn]) return true;
  vector<bool> dp(2*k+1,false);
  dp[a[cn]] = true;
  rep(i,a.size()){
    if(i==cn) continue;
    vector<bool> ndp(2*k+1);
    rep(j,2*k+1) ndp[j] = dp[j];
    for(int j=a[i]; j<2*k+1;j++){
      if(j-a[i]>=0){
	dp[j] = (ndp[j-a[i]] || dp[j]);
      }
    } 
  }
  for(int i=k;i<k+a[cn];i++){
    if(dp[i]) return true;   
  }
  return false;
}




int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,k;
  cin >> n >> k;

  vector<int> a(n);

  rep(i,n) cin >> a[i];
  sort(a.begin(),a.end());

  
  int ub=n-1;//need
  int lb=0;//no need

  if(!need(a,ub,k)){
    cout << n << endl;
    return 0;
  }

  if(need(a,lb,k)){
    cout << 0 << endl;
    return 0;
  }
  
  while(ub-lb>1){
    int mid = (ub+lb)/2;
    if(need(a,mid,k)) ub = mid;
    else lb = mid;
  }

  cout << ub << endl;
    
  

  
  return 0;
    

}
