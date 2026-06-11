#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,a,b;
  int s=0;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a >> b;
    int c= b-a+1;
    s+=c;
  }
  cout << s << endl;
 
  return 0;
}
