#include <bits/stdc++.h>
using namespace std;

inline int64_t ceiling_div(int64_t a, int64_t b){
  int64_t ans= ((a>=0 && b > 0) || (a<=0 && b < 0)) ? (abs(a)+abs(b)-1)/abs(b)
                                                    : -abs(a)/abs(b);
  return ans;
}

int main(){
  using P= pair<int64_t, int64_t>;
  int N;
  cin >> N;

  vector<P> ratios(N);
  for(int i=0; i<N; i++){
    cin >> ratios.at(i).first >> ratios.at(i).second;
  }

  int64_t Avote= 1;
  int64_t Bvote= 1;
  for(auto ratio:ratios){
    int64_t Ashare,Bshare;
    tie(Ashare, Bshare)= ratio;

    int64_t multiply= max(ceiling_div(Avote, Ashare), ceiling_div(Bvote, Bshare));

    Avote= multiply* Ashare;
    Bvote= multiply* Bshare;
  }
  int64_t ans= Avote+ Bvote;

  cout << ans << endl;
}