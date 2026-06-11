#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  if(a!=b && b!=c && a!=c){
    cout << 3 << endl;
  }
  else if((a==b && b!=c) || (b==c && b!=a) || (a==c && b!=c)){
    cout << 2 << endl;
  }
  else{
    cout << 1 << endl;
  }
}
  
