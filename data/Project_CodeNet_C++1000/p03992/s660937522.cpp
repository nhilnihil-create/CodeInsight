#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  for(int i=0;i<s.size();i++){
    cout << s.at(i);
    if(i==3){
      cout << " ";
    }
  }
  cout << endl;
  return 0;
}
