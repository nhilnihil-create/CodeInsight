#include<iostream>
using namespace std;

int main(){
  int n;cin>>n;
  int a,c=0;
  for(int i=0;i<n;i++){
    cin>>a;
    if(a&1) c++;
  }
  if(c&1){
    cout<<"NO"<<endl;
  }else{
    cout<<"YES"<<endl;
  }
}