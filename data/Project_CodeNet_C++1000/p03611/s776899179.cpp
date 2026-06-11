#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> a(N), X(110000);
  for(int i=0; i<N; i++){
    cin >> a.at(i);
    X.at(a.at(i))++;
    X.at(a.at(i)+1)++;
    if(a.at(i)!=0){
      X.at(a.at(i)-1)++;
    }
  }
  int ans=0;
  for(int i: X){
    ans=max(ans,i);
  }
  cout << ans;
  return 0;
}