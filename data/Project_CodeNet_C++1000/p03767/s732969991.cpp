#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(void){
 
  int N;
  cin >> N;
  vector<int> a(3*N);
  for (int i=0; i<3*N; i++) cin >> a[i];
 
  sort((a).rbegin(), (a).rend());
  long long sum =0;
  for (int i=0; i<N; i++){
    sum += a[ i*2 + 1 ];
  }
  
  cout << sum << "\n";
}