#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;cin >> s;
  int k; cin >> k;
  for(int i=0; i<s.size()-1; i++){
    //cout << k << endl;
    if(((int)s.at(i) - 96)==1||k==0){
      continue;
    }else if((27-((int)s.at(i) - 96))<=k){
      
      //cout << (int)s.at(i) << endl;
      k -= 27-((int)s.at(i)-96);
      s.at(i) = 'a';
    }
  }
  //cout << k << endl;
  k = k%26;
  if(k!=0){
    if(122<s.at(s.size()-1)+k){
      s.at(s.size()-1) = (char)96+(s.at(s.size()-1)+k-122);
    }else{
      s.at(s.size()-1) = (char)s.at(s.size()-1)+k;
    }
  }
  cout << s << endl;
}
      