// AC - B - Sum of Three Integers

#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int k,s,i,j,r = 0,x; cin >> k >> s;
  for(i = 0;i <= k;i++)
    for(j = 0;j <= k;j++){
      x = s - (i+j);
      if(0 <= x && x <= k)
        r = r + 1;
    }
  cout << r <<"\n";
  return 0;
}