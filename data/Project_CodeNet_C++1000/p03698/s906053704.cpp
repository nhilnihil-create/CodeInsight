#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
 
  string s;
  cin>>s;


  vector<int> check(26,0);

  for(int i=0;i<s.size();i++){
    int wk=s.at(i)-'a';
    check.at(wk)++;
  }

  bool flg=true;
  for(int i=0;i<26;i++){
    if(check.at(i)>=2){
      flg=false;
      break;
    }
  }

  if(flg)
    cout<<"yes"<<endl;
  else
    cout<<"no"<<endl;

	return 0;
}