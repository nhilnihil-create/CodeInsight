#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int>A(N);
  for(int i=0; i<N; i++){
    cin >> A.at(i);
    A.at(i)--;
  }
  
  int count =0;
  
  for(int i=0; i<N; i++){
    int aite = A.at(i);
    if(A.at(aite)==i)count ++;
  }
  
  cout << count/2 <<endl;
}