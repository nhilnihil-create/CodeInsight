#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n;
  cin>>n;
  int c[n];
  for(int i=0;i<n;i++){
    cin>>c[i];
    }
  int ans=0;
  for(int i=0;i<n;i++){
    if(c[i]==i+1){
      ans++;
      c[i+1]=c[i];
      }
    }
  cout<<ans<<endl;
  return 0;
  }