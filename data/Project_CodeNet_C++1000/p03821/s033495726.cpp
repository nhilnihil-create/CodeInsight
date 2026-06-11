#include<bits/stdc++.h>
using namespace std;
int main(){
  int N; 
  cin >> N;
  unsigned long ans = 0;
  vector<vector<unsigned long>> p(N,vector<unsigned long>(2));
  for(int i = 0; i <N; i++){
    for(int j = 0; j < 2; j++){
    cin >>p.at(i).at(j);
   }
  }
  for(int i = N-1 ; i>=0; i--){
    unsigned long q = (ans+p.at(i).at(0))%p.at(i).at(1);
    if(q != 0){
    ans+=  p.at(i).at(1)-q ;
  }
}
  cout << ans << endl;

}