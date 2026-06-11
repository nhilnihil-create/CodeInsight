#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<string>s(3);
  cin>>s.at(0)>>s.at(1)>>s.at(2);
  vector<int>a(3,0);
  char tmp=s.at(0).at(0);
  char tmp2;
  if(s.at(0).size()==1){
    cout <<"A"<<endl;
    return 0;
  }
  while(1){
    if(a.at(tmp-'a')==s.at(tmp-'a').size()){
      cout <<(char)(int)('A'+tmp-'a')<<endl;
      return 0;
    }
    tmp2=tmp;
    tmp=s.at(tmp-'a').at(a.at(tmp-'a'));
    a.at(tmp2-'a')++;
  }
}