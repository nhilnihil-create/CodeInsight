#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  if(b - a == c - b)  cout << "YES" << endl;
  else cout << "NO" << endl;
}