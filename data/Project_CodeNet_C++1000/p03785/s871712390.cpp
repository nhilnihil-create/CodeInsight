#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,C,K;
  cin >> N >> C >> K;
  vector<int>data(N);
  for(int i=0;i<N;i++){
    cin >> data.at(i);
  }
  sort(data.begin(),data.end());
  int count=0;
  pair<int,int>start;
  start.first=-1;
  for(int i=0;i<N;i++){
    if(start.first>=data.at(i)&&i-start.second<C){
    }
    else{
      count ++;
      start.first=data.at(i)+K;
      start.second=i;
    }
  }
  cout << count << endl;
}
