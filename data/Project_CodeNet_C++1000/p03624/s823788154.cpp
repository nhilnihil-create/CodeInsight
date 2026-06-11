#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  vector<int> a(26);
  for (int i=0;i<s.size();i++){
    for(int j=0;j<26;j++){
      if((int)s[i] == 97+j){
        a[j]++;
      }
    }
  }
  for(int i=0;i<26;i++){
    if(a[i]==0){
      cout << (char)(97+i) << endl;
      return 0;
    }
  }
  cout << "None" << endl;
  
}