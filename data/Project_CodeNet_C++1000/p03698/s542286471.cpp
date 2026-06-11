#include <bits/stdc++.h>
using namespace std;

int main(){
  string str;
  cin >> str;
  vector<int> c(str.size());
  for(int i=0;i<str.size();i++){
    c.at(i)=(int)str.at(i);
  }
  sort(c.begin(),c.end());
  bool A=1;
  for(int i=0;i<str.size()-1;i++){
    if (c.at(i)==c.at(i+1)){
      cout << "no" << endl;
      A=0;
      break;
    }
  }
  if(A){
    cout << "yes" << endl;
  }
}
