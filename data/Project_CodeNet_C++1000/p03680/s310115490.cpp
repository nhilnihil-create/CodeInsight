#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  for(int i=0;i<N;i++){
  	cin >> vec.at(i);
  }
  int a=1;
  int b=vec.at(0);
  while(a<N){
  if(b==2) break;
  else{
  b=vec.at(b-1);
  a++;
  }
  }
  if(a==N) cout << -1;
  else cout << a;
}  