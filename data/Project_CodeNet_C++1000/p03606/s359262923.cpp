#include <bits/stdc++.h>
using namespace std;

int main(){
  int ans =0;
  int N;
  cin>> N;
  
  for(int i=0;i<N;i++){
    int L, R;
    cin>> L>> R;
    ans += R-L+1;
  }
  cout<< ans;
}
