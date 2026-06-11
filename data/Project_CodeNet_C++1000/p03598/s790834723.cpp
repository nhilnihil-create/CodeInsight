#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin >> N >> K;
  int t=0;
  for(int i=0;i<N;i++){
    int x;
    cin >> x;
     if(x<K-x){
       t+=x; 
     }else{
       t+=(K-x);
     }
  }
  t*=2;
  cout << t << endl;
}
