#include <bits/stdc++.h>
using namespace std;

int main() {
  int N=0, A=0, l1=0, l2=0;
  cin >> N;
  
  for(int i=0; i<N; i++){
    cin >> l1 >> l2;
    A+=l2-l1+1;
  }
  
  cout << A << endl;
}