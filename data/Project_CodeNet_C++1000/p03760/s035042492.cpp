#include <bits/stdc++.h>

using namespace std;

int main(){
  string str1;
  string str2;
  cin >> str1 >> str2;
  for(int i=0;i<str1.size();++i){
    cout << str1[i];
    if(i<str2.size())cout<<str2[i];
  }
  cout << endl;
}
