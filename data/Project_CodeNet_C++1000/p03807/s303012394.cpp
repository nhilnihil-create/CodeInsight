#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)

int main(){
  int N;
  cin >> N;
  vector<int> vec(N);
  int count = 0;
  
  rep(i,N){
    cin >> vec[i];
    if(vec[i]%2 == 1) count++;
  }
  
  if(count%2 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}
