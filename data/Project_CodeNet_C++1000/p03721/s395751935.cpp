#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){
int n;
ll k;
cin>>n>>k;

int a[n],b[n];
pair<int,ll>A[n];
rep(i,n){
  cin>>a[i]>>b[i];
  A[i]=make_pair(a[i],b[i]);
}
sort(A,A+n);
pair<int,ll>DP[n];
DP[0]=make_pair(A[0].first,A[0].second);
for(int i=1;i<n;i++){
  DP[i]=make_pair(A[i].first,DP[i-1].second+A[i].second);
  }
rep(i,n){
if(DP[i].second>=k){
  cout<<DP[i].first<<endl;
  return 0;
}

}
  return 0;
}
