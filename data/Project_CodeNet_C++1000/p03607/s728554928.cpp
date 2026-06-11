#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,char>;
using ll=long long;

int main() {
  int N;
  cin >> N;
  set<int> ss;
  vector<int> V(0);
  map<int,int> M;
  int A;
  for (int i=0; i<N; i++) {
    cin >> A;
    M[A]++;
    if (!ss.count(A)) {
      V.push_back(A);
      ss.insert(A);
    }
  }
  
  int S=0;
  for (int i=0; i<V.size(); i++) {
    if (M[V[i]]%2==1) {
      S++;
    }
  }
  cout << S << endl;
}
 