#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin >> s;
  string a = "yes";
  int N = s.size();
  
  
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
    if(s.at(i)==s.at(j)){
    a = "no";
    }
  }
  }
  
  cout << a <<endl;
}