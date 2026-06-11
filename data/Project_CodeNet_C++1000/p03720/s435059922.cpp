#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin>>N>>M;
  vector<int> data(N);
  for(int i=0;i<M;i++){
    int T1,T2;
    cin>>T1>>T2;
    data.at(T1-1)++;
    data.at(T2-1)++;
  }
  for(int i=0;i<N;i++){
    cout<<data.at(i)<<endl;
  }
}
