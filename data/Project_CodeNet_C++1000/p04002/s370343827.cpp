#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <random>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

ll H, W, N;
vector<P> Hpair;
set<P> already;

int main(){
  cin >> H >> W >> N;
  ll res[10];
  for(int i = 0; i < 10; i++) res[i] = 0;
  for(int i = 0; i < N; i++){
    ll a, b;  cin >> a >> b;
    Hpair.push_back(P(a-1, b-1));
  }
  sort(Hpair.begin(), Hpair.end());

  for(int i = 0; i < N; i++){
    ll h = Hpair[i].first;
    ll w = Hpair[i].second;

    for(int j = 0; j < 3; j++){
      for(int k = 0; k < 3; k++){
        int h2 = h-j, w2 = w-k;
        if(h2 < 0 || w2 < 0 || h2 >= H-2 || w2 >= W-2)  continue;
        if(already.find(P(h2, w2)) != already.end())  continue;
        
        int num = 0;
        for(int j2 = 0; j2 < 3; j2++){
          for(int k2 = 0; k2 < 3; k2++){
            int l = 0, r = N;
            int h3 = h2+j2, w3 = w2+k2;
            while(r - l > 1){
              int m = (l + r) / 2;
              if(Hpair[m] <= P(h3, w3)){
                l = m;
              }
              else{
                r = m;
              }
            }
            if(Hpair[l] == P(h3, w3)) num++;
          }
        }
        res[num]++;
        already.insert(P(h2, w2));
      }
    }
  }
  ll sum = 0;
  for(int i = 1; i < 10; i++) sum += res[i];
  res[0] = (H-2)*(W-2) - sum;

  for(int i = 0; i < 10; i++){
    cout << res[i] << endl;
  }

  return 0;
}
