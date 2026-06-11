#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,Ncap,forTwait;
  cin >> N >> Ncap >> forTwait;

  vector<int> data(N);
  for(int i=0; i<N; i++){
    cin >> data.at(i);
  }
  sort(data.begin(), data.end());

  int ans= 0;
  int Nwait= 0;
  int atTtop= 0;
  for(auto atTarrive:data){
    if(Nwait==0){ atTtop= atTarrive; }

    if(atTtop+ forTwait < atTarrive){
      ans++;
      Nwait= 1;
      atTtop= atTarrive;
    }
    else{
      Nwait++;
      if(Nwait==Ncap){
        ans++;
        Nwait= 0;
      }
    }
  }
  if(Nwait > 0){ ans++; }

  cout << ans << endl;
}