#include <bits/stdc++.h>
#define int long long
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;

const int MOD=1000000007;
int INF=100100100100100;

signed main(){
  int a,b,c;cin>>a>>b>>c;
  if(c-b==b-a)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}