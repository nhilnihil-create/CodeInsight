#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  
  int a,b;
  cin >> a >> b;
  
  if(a==1 || a==3 || a==5 || a==7 || a==8 || a==10 || a==12)
  {
    if(b==3 || b==5 || b==7 || b==8 || b==10 || b==12) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  else if(a==4 || a==6 || a==9 || a==11) {
    if(b==6 || b==9 || b==11) cout << "Yes" << endl;
    else{
      cout << "No" << endl;
    }
  }
  else cout << "No" << endl;
  
}
