#include <bits/stdc++.h>
using namespace std;

int64_t solve(int64_t H, int64_t W){
  const int64_t S= H* W;

  int64_t slice= min(H, W);

  int64_t ans= slice;
  for(int Wcut= W/3; Wcut<= W/3+ 1; Wcut++){
    if(Wcut==0){ continue; }
    else{
      vector<int64_t> cross;

      cross.emplace_back(H* Wcut);
      int64_t Wremain= W- Wcut;
      cross.emplace_back(    (H/2)* Wremain);
      cross.emplace_back(((H+1)/2)* Wremain);

      int64_t Smax= *max_element(cross.begin(), cross.end());
      int64_t Smin= *min_element(cross.begin(), cross.end());
      ans= min(ans, Smax- Smin);
    }
  }
  for(int Hcut= H/3; Hcut<= H/3+ 1; Hcut++){
    if(Hcut==0){ continue; }
    else{
      vector<int64_t> cross;

      cross.emplace_back(Hcut* W);
      int64_t Hremain= H- Hcut;
      cross.emplace_back(Hremain* (    W/2));
      cross.emplace_back(Hremain* ((W+1)/2));
  
      int64_t Smax= *max_element(cross.begin(), cross.end());
      int64_t Smin= *min_element(cross.begin(), cross.end());
      ans= min(ans, Smax- Smin);
    }
  }

  return ans;
}

int main(){
  int64_t H,W;
  cin >> H >> W;

  int64_t ans= (H==2   && W==2  ) ? 1
              :(H%3==0 || W%3==0) ? 0
                                  : solve(H, W);
  cout << ans << endl;
}