#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  int H,W,N;
  cin >> H >> W >> N;
  vector<int> A(N);
  vector<int> B(N);
  int sum = 0;
  REP(i, N){
    cin >> A[i];
    sum+=A[i];
    B[i]=sum;
  }
  
  vector<vector<int>> ans(H,vector<int> (W));
  int cnt = 0;
  REP(i,H){
    if(i%2==0){
      REP(j,W){
        if(cnt<=B[0]-1){
          ans.at(i).at(j)=1;
        }
        REP(k,N-1){
          if(cnt>B[k]-1&&cnt<=B[k+1]-1){
            ans.at(i).at(j)=k+2;
          }
        }
        cnt++;
      }
    }else{
      REPR(j,W-1){
        if(cnt<=B[0]-1){
          ans.at(i).at(j)=1;
        }
        REP(k,N-1){
          if(cnt>B[k]-1&&cnt<=B[k+1]-1){
            ans.at(i).at(j)=k+2;
          }
        }
        cnt++;
      }
    }
  }

  REP(i,H){
    REP(j,W){
      if(j!=W-1){
        cout << ans.at(i).at(j) <<" ";
      }else{
        cout << ans.at(i).at(j);
      }
    }
    cout << endl;
  }
}