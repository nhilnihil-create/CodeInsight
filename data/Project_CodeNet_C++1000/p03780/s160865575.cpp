#include <iostream>
#include <algorithm>
using namespace std;

int n, k;

bool need(int*, int);
int main(){
  cin >> n >> k;
  int a[n+1];
  for(int i=1; i<=n; i++) cin >> a[i];
  sort(a+1, a+n+1);

  int l=1, r=n, m;
  if(need(a, 1)){
    cout << 0 << endl;
    return 0;
  }
  if(!need(a, n)){
    cout << n << endl;
    return 0;
  }

  while(l+1<r){
    m = (l+r)/2;
    if(need(a, m)){
      r = m;
    }
    else{
      l = m;
    }
  }

  cout << r-1 << endl;

  return 0;
}

//カードindexが要るならtrue, いらないのならfalse
bool need(int* a, int index){
  int tmp[n];
  for(int i=1, j=1; i<=n; i++){
    tmp[j] = a[i];
    if(i!=index) j++;
  }

  bool dp[n][k];
  for(int i=0; i<n; i++){
    for(int j=0; j<k; j++) dp[i][j] = false;
  }
  dp[0][0] = true;

  for(int i=1; i<n; i++){
    for(int j=0; j<k; j++){
      if(j<tmp[i]) dp[i][j] = dp[i-1][j];
      else dp[i][j] = dp[i-1][j] || dp[i-1][j-tmp[i]];
    }
  }

  for(int j=max(0, k-a[index]); j<k; j++){
    if(dp[n-1][j]) return true;
  }

  return false;
}
