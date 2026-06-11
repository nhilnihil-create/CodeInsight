#include <bits/stdc++.h>
#define int long long
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> P;

const int MOD=1000000007;
int INF=100100100100100;

signed main(){
  int a,b;cin>>a>>b;
  if(a*b*(a+b)%3==0)cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
  return 0;
}