#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,A,B; cin >> N >> A >> B;
  int X; cin >> X;
  long long tired=0;
  for(int i=1; i<N; i++){
    int x; cin >> x;
    tired+=min<long long>((long long)(x-X)*A,B);
    X=x;
  }
  cout << tired << endl;
}