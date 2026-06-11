#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, T;
  cin >> N >> T;

  vector<int> vec(N);
  for (int i=0; i<N; i++){
    cin >> vec.at(i);
  }

  long long sum = 0;
  for (int i=0; i<N-1; i++){
    if (abs(vec.at(i)-vec.at(i+1)) <= T){
      sum += abs(vec.at(i)-vec.at(i+1));
    }
    else {
      sum += T;
    }
  }
  sum += T;
  cout << sum << endl;
}
