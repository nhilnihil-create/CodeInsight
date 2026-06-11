#include <bits/stdc++.h>
using namespace std;

int main(){
  int k, s, sum=0;
  cin >> k >> s;
  
  for(int x=0; x <= k; x++){
    if(x > s) break;
    for(int y=0; y <= k; y++){
      if((x+y) > s) break;
      if((s-(x+y)) <= k) sum++;
    }
  }
  cout << sum << endl;
}
