#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;string t;cin>>s>>t;
  int to=-1;
  if(s.size()<t.size())cout<<"LESS";
  else if(s.size()>t.size())cout<<"GREATER";
  else{
  	for(int i=0;i<s.size();i++){
    	if(s[i]>t[i]){to=1;break;}
      	if(s[i]<t[i]){to=0;break;}
    }
    if(to==-1)cout<<"EQUAL";
    if(to==1)cout<<"GREATER";
    if(to==0)cout<<"LESS";
  
  }
}