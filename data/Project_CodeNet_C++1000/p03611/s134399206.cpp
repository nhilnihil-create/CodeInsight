#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main() {
  int n;
  cin >>n;
  int ans=0;
  map<int,int> p;
  rep(i,n){
    int g;
    cin >>g;
    for(int r=g-1;r<=g+1;r++){
    p[r]++;
    ans=max(ans,p[r]);
    }
  }
  cout << ans << endl;
}