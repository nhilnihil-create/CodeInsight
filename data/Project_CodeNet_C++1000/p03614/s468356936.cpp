#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> p(N);
  for(int i=0;i<N;i++) cin >> p[i];

  int ans=0;
  for(int i=0;i<N;i++){
    if(i+1==p[i]){ ans++; i++; }
  }
  
  cout << ans << endl;
  return 0;
}
