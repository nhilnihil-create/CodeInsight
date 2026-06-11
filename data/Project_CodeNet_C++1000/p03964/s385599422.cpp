#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> T(N);
  vector<long long> A(N);
  for(int i=0; i<N; i++) cin >> T.at(i) >> A.at(i);
  vector<long long> taka(N);
  vector<long long> aoki(N);
  taka.at(0)=T.at(0);
  aoki.at(0)=A.at(0);
  for(int i=1; i<N; i++){
    long long j=1;
    j=max((taka.at(i-1)+T.at(i)-1)/T.at(i) , (aoki.at(i-1)+A.at(i)-1)/A.at(i));
    taka.at(i)=T.at(i)*j;
    aoki.at(i)=A.at(i)*j;
  }
  cout << taka.at(N-1)+aoki.at(N-1) << endl;
}