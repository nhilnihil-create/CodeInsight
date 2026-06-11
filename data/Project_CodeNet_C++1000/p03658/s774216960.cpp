#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N;
  cin >> N;
  int K;
  cin >> K;
  vector<int> l(N);

  for (int i = 0; i < N; i++)
  {
    cin >> l.at(i);
  }

  sort(l.begin(), l.end());

  int sum = 0;
  for (int i = 0; i < K; i++)
  {
    sum += l.at(l.size() - (i + 1));
  }
  cout << sum << endl;
}