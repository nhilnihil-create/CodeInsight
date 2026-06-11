#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  cin>>n;
  ll vec[n],veca[n],vecb[n];
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  for(int i=0;i<n;i++){
    veca[i]=25000*(i+1);
    vecb[i]=25000*(n+1)-veca[i];
  }
  for(int i=0;i<n;i++){
    veca[vec[i]-1]+=i;
  }
  for(int i=0;i<n;i++){
    cout<<veca[i]<<" ";
  }
  cout<<endl;
  for(int i=0;i<n;i++){
    cout<<vecb[i]<<" ";
  }
}