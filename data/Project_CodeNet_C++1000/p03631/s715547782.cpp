#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
  string n;cin>>n;
  string t=n;
  reverse(t.begin(),t.end());
  if(t==n){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
  return 0;
}