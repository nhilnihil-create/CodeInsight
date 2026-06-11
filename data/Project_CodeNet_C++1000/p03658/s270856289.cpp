#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main() {
  int N,K;
  int l[60];
  int sum = 0;
 
  cin >> N>> K;
  for(int i=0;i<N;i++){
    cin >> l[i];
  }
  
  sort(l,l+N,greater<int>());
  for(int i=0;i<K;i++){
    sum += l[i];
  }
  cout << sum<<endl;
  return 0;
}