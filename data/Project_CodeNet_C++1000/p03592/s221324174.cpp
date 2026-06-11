#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M,K;
  cin >> N >> M >> K;
  set<int> s;
  for(int i=0;i<=N;i++){
    for(int j=0;j<=M;j++){
      s.insert(N*j+M*i-i*j*2);
    }
  }
  if(s.count(K)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
