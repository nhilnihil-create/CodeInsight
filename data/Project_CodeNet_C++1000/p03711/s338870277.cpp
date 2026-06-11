#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  if(a==2 || b==2) cout << "No" << endl;
  else if((a==4 || a==6) || (a==9 || a==11)){
    if((b==4 || b==6) || (b==9 || b==11)) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  else if((b==4 || b==6) || (b==9 || b==11)){
    if((a==4 || a==6) || (a==9 || a==11)) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  else cout << "Yes" << endl;
}