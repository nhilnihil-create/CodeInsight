#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int group[12]={1,2,1,3,1,3,1,1,3,1,3,1};
  int a,b;
  cin>>a>>b;
  if(group[a-1]==group[b-1]){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}