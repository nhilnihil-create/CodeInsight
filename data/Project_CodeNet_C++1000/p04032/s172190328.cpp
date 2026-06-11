#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  
  bool flag=false;
  int a,b;
  if(s.size()==2){
    if(s.at(0)==s.at(1)){
      flag=true;
      a=1;b=2;
    }
  }
  else{
  	for(int i=0;i<s.size()-2;i++){
    	if(s.at(i)==s.at(i+1)||s.at(i)==s.at(i+2)||s.at(i+1)==s.at(i+2)){
	      flag=true;
	      a=i+1;
	      b=i+3;
	      break;
	    }
	  }
  }
  if(flag){
    cout<<a<<" "<<b<<endl;
  }else{
    cout<<-1<<" "<<-1<<endl;
  }
}