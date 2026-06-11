#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >>f;
  vector<int> mizu;
  vector<int> sato(1,0);
  for (int i = 0; i <= f / 100 / a; i++) {
    for (int j = 0; j <= f / 100 / b; j++) {
      int ariemizu = (i * a + j * b) * 100;
      if (ariemizu != 0 && ariemizu <= f) mizu.push_back(ariemizu);
    }
  }
  for (int i = 0; i <= (f - 100 * a) / c; i++) {
    for (int j = 0; j <= (f - 100 * a) / d; j++) {
      int ariesato = i * c + j * d;
      if (100 * a + ariesato <= f) sato.push_back(ariesato);
    }
  }
  pair<int, int> answer(100 * a, 0);//first砂糖水,second溶けてる砂糖
  double maxnodo = 0.000000;
  double gendo = 100 * (double)e / (100 + (double)e);
  for (int i = 0; i < mizu.size(); i++) {
    for (int j = 0; j < sato.size(); j++) {
      int satomizu = mizu[i] + sato[j];
      double nodo = 100 * (double)sato[j] / (double)satomizu;
      if (satomizu <= f && maxnodo < nodo && nodo <= gendo) {
        maxnodo = nodo;
        answer = make_pair(satomizu, sato[j]);
      }
    }
  }
  cout << answer.first << ' ' << answer.second;
}