#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  string s;
  cin >> s;
  for(int i=0; i<s.length(); i++){
    if(i%2==1) continue;
    cout << s[i];
  }
  cout << endl;
  return 0;
}
