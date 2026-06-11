#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
 vector<int>v(3);
  for(int i=0;i<3;i++){
   cin>>v.at(i); 
  }
  
  int cnt5,cnt7;
  cnt5=count(v.begin(),v.end(),5);
  cnt7=count(v.begin(),v.end(),7);
  
  if(cnt5==2&&cnt7==1){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
  return 0;
}