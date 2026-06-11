#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  //osの配列
  vector<pair<int,int>> os(N);
  for(int i = 0;i<N;i++){
      int A,B;
      cin>>A>>B;
      os[i]=pair(A,B);
  }
  sort(os.begin(), os.end());
  reverse(os.begin(), os.end());
  
  cout << os[0].first + os[0].second << endl;
  
  
 
}



