#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  
  int count = 0;
  int a;
  for (int i=0;i<n; i++) {
    cin >>a;
    if(a % 2) 
      count++;
  }
  
  if (count % 2) {
    cout<<"NO";
  } else {
    cout<<"YES";
  }
 return 0;
}