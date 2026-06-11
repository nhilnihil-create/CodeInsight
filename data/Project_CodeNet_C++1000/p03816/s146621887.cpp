#include <bits/stdc++.h>
using namespace std;
     
int main() {
  int N;
  cin >> N;
  vector<int> v(N);
  vector<int> u(N);
  for(int i = 0; i < N; i++){
    cin >> v.at(i);
  }
  
  for(int i = 0; i < N; i++){
    u.at(i) = v.at(i);
  }
  
  sort(u.begin(), u.end());
  int i = 0;
  
  while(i < u.size() - 1){
    if(u.at(i) == u.at(i + 1)){
      u.erase(u.begin() + i);
    }
    else{
      i++;
    }
  }
  
  int a = v.size() - u.size();
  
  if(a % 2 == 0){
    cout << u.size() << endl;
    return 0;
  }
  
  cout << u.size() - 1 << endl;
  
}