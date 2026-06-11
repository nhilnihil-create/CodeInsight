#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<pair<int, int>> P(N);
  int A, B;
  for(int i=0; i<N; i++){
    cin >> A >> B;
    P.at(i)=make_pair(A, B);
  }
  sort(P.begin(), P.end());
  cout << P.at(N-1).first+P.at(N-1).second << endl;
}