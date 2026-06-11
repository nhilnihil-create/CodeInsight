#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  vector<int> A(3);
  rep(i,3) cin >> A[i];
  sort(A.begin(),A.end());
  if(A[0] + A[1] == A[2]){
    puts("Yes");
    return 0;
  }
  puts("No");
  return 0;
}
