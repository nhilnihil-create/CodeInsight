#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int mod=1e9+7;
const int N = 1e5+5;

ll dp[3000][55];
ll n,ar,a[55],ans;

int main(){
  // freopen("input.txt","r",stdin);
  cin>>n>>ar;
  for(int i = 1;i <= n;i++){
    cin>>a[i];
    if(i == 1){
      dp[0][0] = 1;
      dp[a[i]][1] = 1;
    }
    else{
      for(int j = 2500;j >= a[i];j--){
	for(int k = i;k >= 1;k--){
	  dp[j][k] = dp[j-a[i]][k-1] + dp[j][k];
	}
      }
    }
  }
  for(int i = 1;i <= n;i++){
    ans += dp[i*ar][i];
  }
  cout<<ans<<endl;
  return 0;
}


