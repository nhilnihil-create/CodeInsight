#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
  char n[2];
  string ans="No";
  cin >> n[0] >>n[1];
  if(n[0]=='9'||n[1]=='9'){
    ans="Yes";
  }

  cout << ans << endl;
      return 0;
}
