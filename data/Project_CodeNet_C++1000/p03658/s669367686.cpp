#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
  int N,K;
  int a[60];
  int total = 0;
  cin >> N >> K;
  for(int i=0;i<N;++i) cin >> a[i];
  sort(a,a+N,greater<int>()); //大きい順
  for(int i=0;i<K;++i){
    total += a[i];
  }
  cout << total << endl;
}