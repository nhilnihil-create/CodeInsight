#include<bits/stdc++.h>
using namespace std;

int main(void){
  int a[7] = {1, 3, 5, 7, 8, 10, 12};
  int b[4] = {4, 6, 9, 11};
  int c[1] = {2};
  int x, y;
  bool ans = true;
  cin >> x >> y;
  for(int i = 0; i < 7; i++){
    for(int j = 0; j < 4; j++){
      for(int l = 0; l < 1; l++){
	if((a[i] == x && b[j] == y) || (a[i] == y && b[j] == x) || (a[i] == x && c[l] == y) || (a[i] == y && c[l] == x) || (b[j] == x && c[l] == y) || (b[j] == y && c[l] == x)){
	  ans = false;
	  break;
	} 
      }
    }
  }
  if(ans) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}
