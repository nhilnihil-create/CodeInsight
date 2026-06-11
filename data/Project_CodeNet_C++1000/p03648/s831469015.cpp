#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <queue>
 
using namespace std;
typedef long long LL;
 
template<typename T>
void print_vec(vector <T>v){
  for(int i=0;i<v.size();i++){
	cout << v[i] << " ";
  }
  cout << endl;
}
 
int main(){
  LL K;
  cin >> K;
  int N=K/10000000000000000;
  if(N<2){
	N=2;
  }
N=N+1;
if(N>50){
N=50;
}
  cout << N <<endl;
  vector<LL> a(N,N-1+K/N);
  for(int i=0;i<K%N;i++){
	a[i]+=N-(K%N-1);
  }
  for(int i=K%N;i<N;i++){
	a[i]-=K%N;
  }
  print_vec(a);
 
  return 0;
}