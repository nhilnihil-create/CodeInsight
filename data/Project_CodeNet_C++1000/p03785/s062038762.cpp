#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  long long ten, K;
  cin >> N >> ten >> K;
  long long T;
  vector<long long>vec(N);
  for(int i=0;i<N;i++){
  cin >> T;
    vec.at(i)=T;
  }
  sort(vec.begin(), vec.end());
  long long A, B, C;
  A=0;//台数
  B=0;//乗車人数
  C=0;//到着時間
  C=vec.at(0);
  B=1;
  A=1;
  for(int j=1;j<N;j++){
  if(vec.at(j)<=C+K && B<ten){
  B++;
  }else{
    A++;
    B=1;
    C=vec.at(j);
  }
  }

  cout << A << endl;
}