#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<pair<int,int>> taisei(N);
  for(int i=0; i<N; i++){
      int x,y;
      cin >> x >> y;
      taisei[i]=pair(x,y);
  }
  sort(taisei.begin(), taisei.end());
  reverse(taisei.begin(), taisei.end());
  
  cout << taisei[0].first + taisei[0].second << endl;
  
//   for(auto x:taisei){
//      cout << x.first << " : " << x.second << endl;
//   }
}


