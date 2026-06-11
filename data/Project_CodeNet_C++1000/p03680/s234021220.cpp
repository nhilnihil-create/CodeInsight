#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,a,b;
  cin >> N;
  vector<int> x(N);
  for(int i=0;i<N;i++){
    cin >> a;
    x.at(i)=a;
  }
  int j=0;
  for(int i=0;i<N;i++){
    b = x.at(j);
    //cout << j << endl;
    //cout << b << endl;
    if(b==2){
      cout << i+1 << endl;
      break;
    }
    j = b-1;
  }
  if (b!=2){
    cout << -1 << endl;
  }
  
}