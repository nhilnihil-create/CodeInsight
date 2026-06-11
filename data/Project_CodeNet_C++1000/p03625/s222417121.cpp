#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){
int n;
cin>>n;
ll a[n];
vector<ll> arr;
map<ll,int>m;
rep(i,n){
  cin>>a[i];
  if(m[a[i]]==1||m[a[i]]==3){
    arr.push_back(-a[i]);
  }
  m[a[i]]++;
}
if(arr.size()<2){

  cout<<0<<endl;
  return 0;
}
sort(arr.begin(),arr.end());
//rep(i,arr.size()){
  //cout<<arr[i]<<endl;
//}
ll ans=arr[0]*arr[1];
cout<<ans<<endl;
  return 0;
}
