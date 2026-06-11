#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int z=0,o=0,t=0;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    if(x%4==0){
    t++;
    }
    else if(x%2==0){
    o++;
    }
    else{
    z++;
    }
  }
  if(z<=t){
    cout<<"Yes"<<endl;
  }
  else if(z-1==t&&o==0){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}