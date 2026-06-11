#include <bits/stdc++.h>
using namespace std;

long comb(int n,int s){
  if(n<s)
    return 0;
  int64_t a=1,b=1;
  for(int i=0;i<s;i++)
    a*=n-i;
  for(int i=1;i<=s;i++)
    b*=i;
  return a/b;
}

int main(){
  int k,s;
  cin >> k >> s;
  cout << comb(s+2,2) - comb(s-k+1,2)*3 +comb(s-k-k,2)*3 << endl;
}