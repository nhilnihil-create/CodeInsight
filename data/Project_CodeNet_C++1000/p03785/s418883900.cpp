#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,C,K;
  cin >> N >> C >> K;
  vector<int>time(N);
  for(int i=0;i<N;i++)
    cin >> time.at(i);
  sort(time.begin(),time.end());
  int ans=0,hito=0,et=0;
  for(int i=0;i<N;i++){
    if(time.at(i)>et||hito>=C){
      ans++;
      et=time.at(i)+K;
      hito=0;
    }
    hito++;
  }
  cout << ans << endl;
  return 0;
}