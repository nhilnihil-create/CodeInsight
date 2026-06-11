#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  cin>>n;
  if(n%2==0){
    int vec[n];
    for(int i=0;i<n;i++){
      cin>>vec[i];
    }
    int x=n-1;
    for(int i=0;i<n;i++){
      if(i<n/2){
        cout<<vec[x]<<" ";
        x-=2;
      }
      if(x==-1){
        x=0;
      }
      if(i>=n/2){
        cout<<vec[x]<<" ";
        x+=2;
      }
    }
    return 0;
  }
  int vec[n];
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  int x=n-1;
  for(int i=0;i<n;i++){
    if(i<n/2+1){
      cout<<vec[x]<<" ";
      x-=2;
    }
    if(x==-2){
      x=1;
    }
    if(i>=n/2+1){
      cout<<vec[x]<<" ";
      x+=2;
    }
  }
}