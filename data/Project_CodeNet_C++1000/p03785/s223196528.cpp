#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  long long C,K;
  cin >> N >> C >> K;
  vector<long long> T(N);
  for(int i=0;i<N;i++){
    cin >> T.at(i);
  }
  sort(T.begin(),T.end());
  int count=0;
  for(int i=0;i<N;){
    count++;
    int NEW=i;
    while(i<N && T.at(i)-T.at(NEW) <=K  && i-NEW<C){
      i++;
    }
  }
    cout << count << endl;
}