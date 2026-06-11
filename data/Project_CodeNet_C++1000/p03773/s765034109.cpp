#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){
  int a, b;
  cin >> a >> b;
  int ans = (a + b) % 24;
  cout << ans << endl;
}