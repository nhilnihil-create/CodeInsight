#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  vector<int> num(26);
  for(int i=0;i<S.size();i++){
    int A=S.at(i)-'a';
    num.at(A)++;
  }
  for(int i=0;i<26;i++){
    if(num.at(i)%2==1){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
      