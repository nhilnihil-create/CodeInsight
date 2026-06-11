#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<vector<int>> data(N, vector<int>(2));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> data.at(i).at(j);
    }
  }
  int sum=0;
  for(int i=0;i<N;i++){
    sum+=data.at(i).at(1)-data.at(i).at(0)+1;
  }
  cout<<sum<<endl;
}