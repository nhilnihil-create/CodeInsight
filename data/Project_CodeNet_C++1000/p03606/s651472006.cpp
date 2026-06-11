#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int ans=0;
  
  for (int i=0;i<N;i++){
    int R,L;
    cin >> R>>L;
    ans +=L-R+1;
  }
  
  cout << ans << endl;
  return 0;
}