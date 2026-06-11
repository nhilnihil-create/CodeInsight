#include <bits/stdc++.h>
using namespace std;

int64_t solve(int64_t H, int64_t W){
  const int64_t S= H* W;

  vector<int64_t> cands;
  int64_t slice= min(H, W);
  cands.emplace_back(slice);

  vector<vector<int64_t>> cross(4);
  int cnt= 0;
  for(int Wcut= W/3; Wcut<= W/3+ 1; Wcut++){
    if(Wcut==0){
      cross.at(cnt).emplace_back(INT64_MAX);
      cnt++;
      continue;
    }
    else{
      cross.at(cnt).emplace_back(H* Wcut);
      int64_t Wremain= W- Wcut;
      cross.at(cnt).emplace_back(    (H/2)* Wremain);
      cross.at(cnt).emplace_back(((H+1)/2)* Wremain);

      int64_t Smax= *max_element(cross.at(cnt).begin(), cross.at(cnt).end());
      int64_t Smin= *min_element(cross.at(cnt).begin(), cross.at(cnt).end());
      cands.emplace_back(Smax- Smin);

      cnt++;
    }
  }
  for(int Hcut= H/3; Hcut<= H/3+ 1; Hcut++){
    if(Hcut==0){
      cross.at(cnt).emplace_back(INT64_MAX);
      cnt++;
      continue;
    }
    else{
      cross.at(cnt).emplace_back(Hcut* W);
      int64_t Hremain= H- Hcut;
      cross.at(cnt).emplace_back(Hremain* (    W/2));
      cross.at(cnt).emplace_back(Hremain* ((W+1)/2));
  
      int64_t Smax= *max_element(cross.at(cnt).begin(), cross.at(cnt).end());
      int64_t Smin= *min_element(cross.at(cnt).begin(), cross.at(cnt).end());
      cands.emplace_back(Smax- Smin);
  
      cnt++;
    }
  }

  return *min_element(cands.begin(), cands.end());
}

int main(){
  int64_t H,W;
  cin >> H >> W;

  int64_t ans= (H==2   && W==2  ) ? 1
              :(H%3==0 || W%3==0) ? 0
                                  : solve(H, W);
  cout << ans << endl;
}