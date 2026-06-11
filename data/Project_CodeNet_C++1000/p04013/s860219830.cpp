#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[52][52][3000] ;
int arr[52];
int n , a;
ll recur(int pos , int nisi , int sum ){
  if(pos==n){
    if((double)sum/nisi==a){
      return 1;
    }
    else
     return 0;
  }
  if(dp[pos][nisi][sum]!=-1){
    return dp[pos][nisi][sum];
  }
  ll way1 =0,way2= 0;
  way1=recur(pos+1,nisi+1,sum+arr[pos]);
  way2=recur(pos+1,nisi,sum);
  dp[pos][nisi][sum]=way1+way2;
  return dp[pos][nisi][sum];
}
int main(){
 cin >> n >> a ;
 for(int i=0;i<n;i++){
    cin >> arr[i];
 }
 memset(dp,-1,sizeof(dp));
 ll res = recur(0,0,0);
 cout << res <<endl;
 return 0;
}