#include <bits/stdc++.h>
using namespace std;
 
int main() {

  int N,T;

  cin >> N >> T ;

  vector<int> t(N);

  for(int i=0;i<N;i++) cin >> t.at(i);

  int64_t ans=0;

  for(int i=1;i<N;i++) ans+=min(T,t.at(i)-t.at(i-1));//一人対策のためにあえてiの条件とtの()内部の条件を特異的に設定している。
  //i=1からはじめることで、要素が一つしかないときはスルーされる

  ans+=T;//最後に出続けるお湯
  
  cout << ans << endl;

  return 0;
}