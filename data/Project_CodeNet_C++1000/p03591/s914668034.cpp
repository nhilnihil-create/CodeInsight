#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  if(s.length() < 4){
    cout << "No" << endl;
    return 0;
  }
  if(s[0] == 'Y' && s[1] == 'A' && s[2] == 'K' && s[3] == 'I')
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
