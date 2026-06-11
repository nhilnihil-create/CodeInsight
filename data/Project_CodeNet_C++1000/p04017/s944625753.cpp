#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define int long long

const int MOD = 1000000007;

signed main(){

  int  num = 0;
  int N;
  int L, Q;
  vector<int> x;
  vector<vector<int>> table;

  cin>>N;

  x.resize(N);

  for(int n = N; n > 0; n >>= 1, num++);

  table.resize(num+2, vector<int>(N));

  for(int i = 0; i < N; i++){
    cin>>x[i];
  }

  cin>>L>>Q;

  for(int i = 0; i < N; i++){
    table[0][i] = upper_bound(x.begin(), x.end(), x[i] + L) - x.begin() - 1;
  }

  for(int i = 1; i < (int)table.size(); i++){
    for(int j = 0; j < N; j++){

       table[i][j] = table[i-1][table[i-1][j]];

       //cout<<table[i-1][j]<<" ";
    }
    // cout<<endl;
  }


  for(int i = 0; i < Q; i++){
    int a, b;
    int ans = 0;

    cin>>a>>b;
    a--, b--;

    if(a > b) swap(a, b);

    for(int k = table.size()-1; k >= 0; k--){
      if(table[k][a] < b){
        a = table[k][a];
        ans += 1<<k;
      }
    }

    if(a != b) ans++;

    cout<<ans<<endl;
  }

  return 0;
}
