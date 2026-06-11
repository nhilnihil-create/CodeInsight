#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n;
  cin >> n;
  bool ok = 0;
  if(n%10==9)ok=1;
  if(n/10==9)ok=1;
  if(ok)cout << "Yes" << endl;
  else cout << "No" << endl;
}