#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int vec[n];
  for(int i=0;i<n;i++){
    cin>>vec[i];
    vec[i]--;
  }
  int ans=0;
  for(int i=0;i<n;i++){
    if(vec[vec[i]]==i){
      ans++;
    }
  }
  cout<<ans/2<<endl;
}