 #include <bits/stdc++.h>
using namespace std;

int main() {
 int N, M; cin >> N >> M;
  vector<int> num(N);
  vector<int> a(M);
  vector<int> b(M);
  for(int i = 0; i < M;i++) cin >> a[i] >> b[i];
  for(int i = 0; i < M;i++){
    num[a[i]-1]++;
    num[b[i]-1]++;
  }
  for(int i = 0; i< N;i++){
    cout << num[i] << endl;
  }
}
