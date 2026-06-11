#include <iostream>
using namespace std;
int main(){
  string s;
  cin >> s;
  int size = s.size();
  int i;
  for(i=0;i<size-1;i++){
    if(s[i]==s[i+1]){
      cout << i+1 << " " <<i+2 << "\n";
      return 0;
    }
    else if(s[i]==s[i+2]){
      cout << i+1 << " " <<i+3 << "\n";
      return 0;
    }
  }
  cout << -1 << " " << -1 << "\n";
  return 0;
}