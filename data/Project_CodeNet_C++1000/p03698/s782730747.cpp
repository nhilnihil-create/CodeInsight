#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
  cin>>s;
  vector<int >pos(26,0);
  for(int i=0;i<s.length();i++){
  	pos[s[i]-'a']++;
  }
  int yes = 1;
  for(int i=0;i<26;i++){
  	if(pos[i]>1){yes=0;break;}
  }
  if(yes==1)cout<<"yes";
  else cout<<"no";
}