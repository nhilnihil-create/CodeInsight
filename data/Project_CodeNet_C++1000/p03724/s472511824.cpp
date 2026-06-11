#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, M; cin >> N >> M;
  vector<int> num(N + 1);
  for(int i = 0; i < M; i++){
    int a, b; scanf("%d%d", &a, &b);
    num[a]++; num[b]++;
  }
  bool ok = true;
  for(int i = 0; i <= N; i++){
    if(num[i] % 2 == 1) ok = false;
  }
  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
}
