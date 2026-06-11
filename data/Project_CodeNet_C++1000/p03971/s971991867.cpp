#include <bits/stdc++.h>
using namespace std;

int main() {
 int n,a,b;
  string member;
  cin >> n >> a >> b >> member;
  
  int passNum = 0;
  int passAbroad = 0;
 
  for(int i = 0; i < n; i++) {
    char current = member.at(i);
 	if(current == 'a' && passNum < (a+b)) {
      cout << "Yes" << endl;
      passNum++;
    } else if(current == 'b' && passNum < (a+b)
              && passAbroad < b){
      cout << "Yes" << endl;
      passNum++;
      passAbroad++;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}