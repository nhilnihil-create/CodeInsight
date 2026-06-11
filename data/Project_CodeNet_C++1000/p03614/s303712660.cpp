#include<iostream>
#include<vector>

using namespace std;

int N;
vector<int> p;
int main () {
  cin >> N;
  int pi;
  for (int i = 0; i < N; i++) {
    cin >> pi;
    p.push_back(pi);
  }
  int cnt = 0;
  for (int i = 0; i < N - 1; i++) {
    if(p[i] == i + 1) {
      swap(p[i], p[i + 1]);
      cnt += 1;
    }
  }
  if(p[N - 1] == N) {
    cnt += 1;
  }

  cout << cnt << endl;
  
  return 0;
}
