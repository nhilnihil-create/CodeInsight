#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M; cin >> N >> M;
  vector<int> v(N,0);
  for(int i=0; i<2*M; i++){
    int a;
    cin >> a;
    v[a-1]++;
  }
  bool f=true;
  for(int i=0; i<N; i++){
    if(v[i]%2==1) f=false;
  }
  cout << (f?"YES":"NO") << endl;
}