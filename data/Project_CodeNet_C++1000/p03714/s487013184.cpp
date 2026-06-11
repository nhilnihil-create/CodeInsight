#include <bits/stdc++.h>
#define int long long
using namespace std;
using Graph = vector<vector<int>>;

signed main()
{
  int N;
  cin >> N;

  priority_queue<int, vector<int>, greater<int>> mae;
  int maesum = 0;
  vector<int> A(3*N);
  for( int i = 0; i < 3*N; i++ ){
    cin >> A.at(i);
    if( i < N ){
      mae.push(A.at(i));
      maesum += A.at(i);
    }
  }

  vector<int> maeK(N+1, 0);
  maeK.at(0) = maesum;

  int cnt = 1;
  for( int i = N; i < 2*N; i++ ){
    mae.push(A.at(i));
    maesum += (A.at(i) - mae.top());
    mae.pop();
    maeK.at(cnt) = maesum;
    cnt++;
  }
  
  priority_queue<int> ushiro;
  int usum = 0;
  for( int i = 3*N-1; i >= 2*N; i-- ){
    ushiro.push(A.at(i));
    usum += A.at(i);
  }
  
  vector<int> ushiroK(N+1, 0);
  ushiroK.at(N) = usum;
  cnt = N-1;
  for( int i = 2*N-1; i >= N; i-- ){
    ushiro.push(A.at(i));
    usum += (A.at(i) - ushiro.top());
    ushiro.pop();
    ushiroK.at(cnt) = usum;
    cnt--;
  }
  
  int ans = -1000000000000000;

  for( int i = 0; i <= N; i++ ){
    if( maeK.at(i) - ushiroK.at(i) > ans ) ans = maeK.at(i) - ushiroK.at(i);
  }
  cout << ans << endl;
}