#include<iostream>
using namespace std;
int main(void){
  int n;
  string s;
  cin>>n>>s;
  int sum=0;
  string head="";
  string end="";
  for(int i=0;i<n;i++){
    if(s[i]=='('){
      sum+=1;
    }
    if(s[i]==')'){
      sum-=1;
    }
    if(sum<0){
      head+='(';
      sum+=1;
    }
  }
  while(sum>0){
    end+=')';
    sum-=1;
  }
  cout<<head<<s<<end<<endl;
  return 0;
}