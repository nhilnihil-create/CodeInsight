#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> t(N);
  int ans = 0;
  for(int i = 0; i< N; i++){
    cin >> t.at(i);
    ans += t.at(i);
  }
  int M;
  cin >> M;
  int i = 0;
  while(i<M){
    int p,x;
    cin >> p >> x;
    cout << ans-t.at(p-1) +x << endl;
    i++;
  }
  

}