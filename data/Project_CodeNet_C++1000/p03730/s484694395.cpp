#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int k=a;
  string s="NO";
  for(int i=0;i<b;i++){
    if(k%b==c){
      s="YES";
      break;
    }
    k+=a;
  }
  cout << s << endl;
}