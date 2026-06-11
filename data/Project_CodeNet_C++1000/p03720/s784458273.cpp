#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N, M;
  
  cin >> N >> M;
  
  vector<int> cnt(N);
  for(int i = 0;i < M;i++){
    int a, b;
    cin >> a >> b;
    cnt.at(--a)++;
    cnt.at(--b)++;
  }
  
  for(int i = 0;i < N;i++) cout << cnt.at(i) << endl;
  
  return 0;
}