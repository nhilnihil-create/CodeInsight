#include <bits/stdc++.h>
using namespace std;
int n,i;
int main(){
  cin>>n;
  for(i=1;n-i>0;++i)n-=i;
  cout << i << endl;
  return 0;
}