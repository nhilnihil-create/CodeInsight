#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

int main()
{
  int N;
  int a[110000]={0};
  ll res=1;
  cin >> N;

  rep(i,N) {
    int aa;
    cin >> aa;
    a[aa]++;
  }

  int n=N%2;
  bool can=true;
  if(a[0]>n) can=false;
  if(N%2==1 && a[0]==0) can=false;
  FOR(i,1,N-1){
    if(i%2==n && a[i]) can=false;
    if(a[i]>2) can=false;
  }
  if(can){
    rep(i,N/2){
      res = (res*2)%MOD;
    }
    cout << res << endl;
  }
  else{
    cout << 0 << endl;
  }

}