#include<bits/stdc++.h>
using namespace std;


int main(){
  int n;
  cin >> n;
  if(n>=64) cout << "64";
  else if (n>=32) cout << "32";
  else if(n>=16) cout << "16";
  else if(n>=8) cout << "8";
  else if(n>=4) cout << "4";
  else if(n>=2) cout << "2";
  else cout << "1";
  cout << endl;
  return 0;
}
