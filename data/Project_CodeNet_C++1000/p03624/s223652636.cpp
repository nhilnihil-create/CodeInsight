#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
 
  string s;
  cin>>s;

  vector<int> found_char(26,0);
  for(int i=0;i<s.size();i++){
    char wk=s.at(i);
    found_char.at(wk-'a')++;
  }

  bool flg=false;
  char not_found='?';
  for(int i=0;i<26;i++){
    if(found_char.at(i)==0){
      not_found=(char)(i+'a');
      break;
    }

    if(i==26-1)
      flg=true;
  }


  if(flg)
    cout<<"None"<<endl;
  else
    cout<<not_found<<endl;

	return 0;
}