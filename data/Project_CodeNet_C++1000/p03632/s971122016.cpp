#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int A,B,C,D;
  cin>>A>>B>>C>>D;
  
  int low=max(A,C);
  
  int up=min(B,D);
  
  
  cout<<max(0,up-low)<<endl;
}