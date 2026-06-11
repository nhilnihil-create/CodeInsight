#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define RET return 0
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++) cin >> a[i] >> b[i];
  LL ans=0,tmp;
  int ms;
  for(int i=0;i<=30;i++){
    tmp=0;
    if(k&(1<<i)){
      ms=(1<<30)-1-(k-(k&((1<<(i+1))-1))+((1<<i)-1));
    }else{
      ms=(1<<30)-1-k;
    }
    for(int j=0;j<n;j++){
      if((ms&a[j])==0) tmp+=b[j];
    }
    ans=max(ans,tmp);
  }
  cout << ans << endl;
  return 0;
}