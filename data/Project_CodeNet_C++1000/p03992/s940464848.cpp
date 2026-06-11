#include <iostream>
using namespace std;
int main(){
  string s;cin>>s;
  for(int i = 0; 13 > i; i++){
    if(i < 4) cout << s[i];
    else if(i == 4)cout << " ";
    else cout << s[i-1];
  }
  cout << endl;
}