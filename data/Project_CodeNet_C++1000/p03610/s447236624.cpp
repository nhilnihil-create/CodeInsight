#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  char S[100000];
  int count = 0;
  for(int i;i<s.size();i++){
    if(i%2==0){
      count++;
    }
  }
  for(int i;i<count;i++){
    S[i]=s[2*i];
  }
  cout << S << endl;
}