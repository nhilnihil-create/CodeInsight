#include <bits/stdc++.h>
#include <vector>
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;
using namespace std;
int main(){
  int n;
  cin >> n;
  int lowScore = 1000000000;
  int lowRank = 0;
  rep(i, n){
    int a;
    cin >> a;
    lowRank = max(lowRank, a);
    int b;
    cin >> b;
    lowScore = min(lowScore, b);
  }
  cout << lowScore + lowRank << endl;
  return 0;
}