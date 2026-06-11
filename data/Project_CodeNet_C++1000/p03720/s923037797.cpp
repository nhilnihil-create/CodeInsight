#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M ;
  vector<int> A(N,0);
  int a;
  
  for (int i=0;i<M*2;i++){
    cin >> a;
    A.at(a-1)++;
  }  

  for (int j=0;j<N;j++){
    cout << A.at(j) << endl;
  }
}