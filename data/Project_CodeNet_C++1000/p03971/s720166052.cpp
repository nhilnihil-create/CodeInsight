#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define _ << ' ' <<
using namespace std;
using ll = long long;

int main()
{
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  int br = 0, br1 = 0;
  int x = a + b;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'a') {
      if(br < x){
        cout << "Yes" << "\n";
        br++;
      }
      else 
        cout << "No" << "\n";
    }
    else if(s[i] == 'b') {
      if((br < x) && (br1 < b)) {
        cout << "Yes" << "\n";
        br++; br1++;
      }
      else 
        cout << "No" << "\n";
    }
    else {
      cout << "No" << "\n";
    }
  }

}
