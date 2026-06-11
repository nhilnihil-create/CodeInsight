#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main(){
  int N;
  ll W;
  cin >> N >> W;
  pair<ll,int> p[N];
  for(int i=0;i<N;i++) cin >> p[i].first >> p[i].second;
  ll w1 = p[0].first;

  sort(p,p+N);

  vector<int> val[4];
  for(int i=N-1;i>=0;i--){
    int ind = p[i].first - w1;
    val[ind].push_back(p[i].second);
  }

  /*for(int i=0;i<4;i++){
    for(int j=0;j<val[i].size();j++){
      cout << val[i][j] ;
    }
    cout << endl;
  }*/

  //累積和
  ll sum[4][101];
  fill(sum[0],sum[4],0LL);
  for(int i=0;i<4;i++){
    for(int j=1;j<=(int)val[i].size();j++){
      sum[i][j] = sum[i][j-1] + val[i][j-1];
    }
  }

  /*for(int i=0;i<4;i++){
    for(int j=0;j<=(int)val[i].size();j++){
      cout << sum[i][j] ;
    }
    cout << endl;
  }*/

  ll ans = 0LL;
  for(int i=0 ; i<=(int)val[0].size() ; i++){
    for(int j=0 ; j<=(int)val[1].size() ; j++){
      for(int k=0 ; k<=(int)val[2].size() ; k++){
        if(i*w1 + j*(w1+1) + k*(w1+2) <= W){
          int l = (W-((i+j+k)*w1 + j + 2*k)) / (w1 + 3);
          ll res = sum[0][i] + sum[1][j] + sum[2][k] + sum[3][l];
          ans = max(ans, res);
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}
