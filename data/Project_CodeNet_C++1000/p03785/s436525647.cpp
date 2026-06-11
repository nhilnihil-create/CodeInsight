#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define all(vec) vec.begin(),vec.end()
int main() {
  int N,C,K;  cin >> N >> C >> K;
  vector<int> T(N);
  rep(i,N) cin >> T.at(i);
  sort(all(T));

  int bus = 1;
  int psng = 0;
  int bustime = T.at(0)+ K;  //1台目の時間6
  rep(i,N){
      if (T.at(i) <= bustime && psng < C) psng++;
      else{
        bus++;
        psng=1;
        bustime = T.at(i) + K;
//        cout << i+1 <<" bus " << bus << "-" << bustime << endl;
      }
  }
  cout << bus << endl;
}
