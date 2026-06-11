#include <bits/stdc++.h> 

using namespace std; 
int c[4];
int main(){ 
  int w,a,b;
  cin>>w>>a>>b;
  if(a>b) {
    swap(a, b);
  }
  if(b-a-w<0) cout<<0;
  else cout<<b-a-w;
}
 