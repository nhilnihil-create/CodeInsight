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
  int N;
  cin >> N;
  vector<int> A(N);
  map<int,int> mp;
  REP(i, N){
    cin >> A[i];
    mp[A[i]]++;
  }
  
  int cnt = 0;
  for(auto x:mp){
    if(x.second%2==0){
      cnt++;
    }
    if(x.second%2==0&&x.second>=2){
      x.second=2;
    }else if(x.second%2==1&&x.second>=3){
      x.second=1;
    }
  }

  if(cnt%2==0){
    cout << mp.size() << endl;
  }else{
    cout << mp.size()-1 << endl;
  }
}