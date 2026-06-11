#include<iostream>
#include <algorithm>
using namespace std;
int main(){
  int N, K, sum;
  int a[60];
  
  cin >> N >> K;
  for(int i=0;i<N;++i) cin >> a[i];
  
  sort(a, a+N, greater<int>());
  for(int j=0;j<K;++j) sum+=a[j];
  
  cout << sum;
}
