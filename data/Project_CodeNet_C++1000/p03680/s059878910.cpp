#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,x=1,cnt=0;
  cin >> N;
  vector<int>a(N);
  for(int i=0; i<N; i++)
    cin >> a.at(i);
  while(x!=2){
    x = a.at(x-1);
    cnt++;
    if(cnt>N){
      cout << -1 << endl;
      return 0;
    }
  }
  cout << cnt << endl;
}