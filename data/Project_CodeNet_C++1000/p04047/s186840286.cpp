#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define M 1000000007
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin>>n;
  ll arr[2*n];
  ll m=2*n;
  for(ll i=0;i<m;i++) cin>>arr[i];
  sort(arr,arr+m);
  ll sum=0;
  for(ll i=0;i<m;i+=2) sum+=arr[i];
  cout<<sum;
  
    
  
}