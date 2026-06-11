#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> E, O;

int main() {
  cin >> N >> M;
  for(int i = 0; i < M; ++i) {
    int a; cin >> a; (a % 2 == 0 ? E : O).push_back(a);
  }
  int e = E.size(), o = O.size();
  if(o > 2) cout << "Impossible" << endl;
  else if(M == 1) {
    int a = (e != 0 ? E : O)[0];
    cout << a << endl;
    if(a == 1) {
      cout << 1 << endl;
      cout << 1 << endl;
    } else {
      cout << 2 << endl;
      cout << a - 1 << " " << 1 << endl;
    }
  } else if(o == 0) {
    for(int i = 0; i < e; ++i) cout << (i == 0 ? "" : " ") << E[i];
    cout << endl;
    cout << M << endl;
    cout << E[0] + 1;
    for(int i = 1; i < e - 1; ++i) cout << " " << E[i];
    cout << " " << E[e - 1] - 1 << endl;
  } else if(o == 1) {
    cout << O[0];
    for(int i = 0; i < e; ++i) cout << " " << E[i];
    cout << endl;
    cout << M << endl;
    cout << O[0] + 1;
    for(int i = 0; i < e; ++i) cout << " " << E[i] - (i == e - 1 ? 1 : 0);
    cout << endl;
  } else {
    cout << O[0];
    for(int i = 0; i < e; ++i) cout << " " << E[i];
    cout << " " << O[1];
    cout << endl;
    bool one = O[0] == 1;
    cout << M - (one ? 1 : 0) << endl;
    if(!one) cout << O[0] - 1 << " ";
    for(int i = 0; i < e; ++i) cout << E[i] << " ";
    cout << O[1] + 1 << endl;
  }
  return 0;
}
