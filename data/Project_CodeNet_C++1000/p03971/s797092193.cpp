#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,b;
  cin>>n>>a>>b;
  string s;
  cin>>s;
  int count=0;
  int countb=1;
  for(int i=0;i<n;i++){
    if(s[i]=='a'){
      if(count<a+b){
        cout<<"Yes"<<endl;
        count++;
      }else{
        cout<<"No"<<endl;
      }
    }else if(s[i]=='b'){
      if(count<a+b && b>=countb){
        cout<<"Yes"<<endl;
        count++;
        countb++;
      }else{
        cout<<"No"<<endl;
      }
    }else{
      cout<<"No"<<endl;
    }
  }
}