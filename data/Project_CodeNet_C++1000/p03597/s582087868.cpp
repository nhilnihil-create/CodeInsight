#include <bits/stdc++.h>
#include<vector>
using namespace std;
#define rep(i, n)        for(int i=0; i<(int)(n); ++i)
int sub(int i,int j){
  int b=1;
  if(j==3)return 0;
  for(int a=1;a<=i;a++){
    b*2;
  }
  return 1/b+(i+1)*sub(i+1,j+1);
}
int main() {
  int a,b;
  int c,d=1;
  cin>>a>>b;
  cout<<a*a-b;
}