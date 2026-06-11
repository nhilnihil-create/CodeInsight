#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n;
  cin >> n;
  vector<int> x(n);
  for(int i=0;i<n;i++){
    cin >> x[i];
  }
  int l;
  cin >> l;
  int sz=0,c=1;
  while(c<n) c*=2,sz++;

  vector<vector<int>> lp(n,vector<int>(sz));
  for(int i=0;i<n;i++){
    lp[i][0]=upper_bound(all(x),x[i]+l)-x.begin()-1;
  }
  for(int i=1;i<sz;i++){
    for(int j=0;j<n;j++){
      lp[j][i]=lp[lp[j][i-1]][i-1];
    }
  }

  vector<vector<int>> rp(n,vector<int>(sz));
  for(int i=0;i<n;i++){
    rp[i][0]=lower_bound(all(x),x[i]-l)-x.begin();
  }
  for(int i=1;i<sz;i++){
    for(int j=0;j<n;j++){
      rp[j][i]=rp[rp[j][i-1]][i-1];
    }
  }

  int q;
  cin >> q;
  int a,b;
  for(int t=0;t<q;t++){
    cin >> a >> b;
    a--,b--;
    int ans=0;
    if(a<b){
      for(int i=sz-1;i>=0;i--){
        if(lp[a][i]<b){
          ans|=(1<<i);
          a=lp[a][i];
          if(a==b) break;
        }
      }
    }else{
      for(int i=sz-1;i>=0;i--){
        if(rp[a][i]>b){
          ans|=(1<<i);
          a=rp[a][i];
          if(a==b) break;
        }
      }
    }
    cout << ans+1 << endl;
  }
  return 0;
}
