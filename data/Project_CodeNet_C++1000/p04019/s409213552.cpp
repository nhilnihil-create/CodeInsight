#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
  cin>>s;
  if(s.find('S')!=string::npos&&s.find('N')==string::npos||
    s.find('N')!=string::npos&&s.find('S')==string::npos||
    s.find('W')!=string::npos&&s.find('E')==string::npos||
    s.find('E')!=string::npos&&s.find('W')==string::npos){
      cout<<"No";
  }else cout<<"Yes";
}