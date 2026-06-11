#include<bits/stdc++.h>
using namespace std;

int main () {
  int N;
  int sm,bg;
  cin >> N;
  vector<int> AB(N);
  for (int i=0; i<N; i++) {
    cin >> AB[i];
  }
  sort(AB.begin(),AB.end());
  if (AB[N-1] - AB[0] > 1) {
    cout << "No" << endl;
  }
  else if (AB[N-1] - AB[0] == 1) {
    sm = 1;
    for (int i=1; i<N; i++) {
      if (AB[0] == AB[i]) {
        sm++;
      }
    }
    bg = N-sm;
    if (sm < AB[N-1] && AB[N-1] <= sm + bg/2) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
  else {
    if (AB[0] == N-1 || (1 <= AB[0] && AB[0] <= N/2)) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
}