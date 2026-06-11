#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

const int N = 100001;
const int MOD = 998244353;

struct Fenwick{
  vector<int> tree;
  Fenwick(int n){
    tree.resize(n + 1);
  }
  Fenwick(){}
  void add(int in, int val){
    in++;
    while(in < tree.size()){
      tree[in] += val;
      in += in & -in;
    }
  }
  ll get(int in){
    in++;
    ll res = 0;
    while(in){
      res += tree[in];
      in -= in & -in;
    }
    return res;
  }
  ll get(int l, int r){
    if(l == 0)return get(r);
    return get(r) - get(l - 1);
  }
  ll get_at(int in){
    return get(in, in);
  }
};

bool done[301][301];
int main()
{
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);

  int n;
  cin >> n;
  int A[n][n];
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      cin >> A[i][j];
    }
  }
  for(int i = 0;i < n;i++)
    for(int j = 0;j < n;j++)
      for(int k = 0;k < n;k++)
        if(A[i][j] + A[j][k] < A[i][k] || A[i][j] != A[j][i]){
          cout << -1;
          return 0;
        }
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      for(int k = 0;k < n;k++){
        if(i == j || i == k || j == k)continue;
        if(A[i][j] + A[j][k] == A[i][k]){
          done[i][k] = 1;
        }
      }
    }
  }
  ll res = 0;
  for(int i = 0;i < n;i++){
    for(int j = i + 1;j < n;j++){
      if(!done[i][j])
        res += A[i][j];
    }
  }
  cout << res;
}

