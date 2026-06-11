#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  if(n/10==9){
    cout<<"Yes"<<endl;
  }
  else if(n%10==9){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}
