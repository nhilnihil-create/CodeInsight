#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int kazu = 0;
  cin >> N;
  for(int i = 0; i < N; i++)
  {
    int l, r;
    cin >> l;
    cin >> r;
    int sore = (r - l + 1);
    kazu += sore;
    if(i == N - 1)
      cout << kazu << endl;
  }
}
