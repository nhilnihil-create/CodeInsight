#include<iostream>
#include<cmath>
using namespace std;
#define ll long long
#define mod 1000000007
#define for(i,n) for(int i=0;i<(int)n;i++)
int main(){
	int n;
  cin>>n;
  int arr[n];
  for(i,n)cin>>arr[i];
  int  check[n];
  for(i,n)check[i] = 2;
  for(i,n){
    if(n%2==0){
    if(arr[i]%2==0){cout<<0;return 0;}
      check[arr[i]]--;
      if(check[arr[i]]<0){cout<<0;return 0;}
    }
    else{
    if(arr[i]%2!=0){cout<<0;return 0;}
      check[arr[i]]--;
      if(check[arr[i]]<0){cout<<0;return 0;}
    }
  }
if(n%2==0){
if(check[0]!=2){cout<<0;return 0;}
}
  else{
  if(check[0]!=1){cout<<0;return 0;}
  }
  int l = n/2;
  int ans = 1;
  for(i,l)ans = (ans*2)%mod; 
  
  cout<<ans;
}