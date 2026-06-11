#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int64_t>a(N);
  vector<int64_t>b(N);
  for(int i=0;i<N;i++)
    cin >> a.at(i) >> b.at(i);
  int64_t ans=0;
  for(int i=N-1;i>=0;i--){
    if((a.at(i)+ans)%b.at(i)!=0)
      ans+=b.at(i)-(a.at(i)+ans)%b.at(i);
    //cout << ans << endl;
  }
  cout << ans << endl;
  return 0;
}