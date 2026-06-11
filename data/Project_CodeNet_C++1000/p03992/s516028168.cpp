#include<bits/stdc++.h>
using namespace std;
int main(){
  char s[13];
  cin >> s;
  for(int i=0;i<12;i++){
    cout << s[i];
    if(i==3){
      cout << " ";
    }
  }
  cout << endl;
}
