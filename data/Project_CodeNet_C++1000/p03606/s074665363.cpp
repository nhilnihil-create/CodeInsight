#include <bits/stdc++.h>
using namespace std;

int main(){
  int i, N, total=0;
  cin >> N;
  int l[N], r[N];
  for(i=0; i<N; i++){
    cin >> l[i] >> r[i];
    total += r[i]-l[i]+1;
  }

  cout << total << endl;

  return 0;
}