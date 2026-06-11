#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int n,m,a[100100];
bool b[100100]={0,1};

int main(){
  cin >>n >>m;
  for(int i = 1; i<=n; i++) a[i]=1;
  for(int i = 1; i<=m; i++){
    int x,y; cin >>x >>y;
    if(b[x]) {
      b[y]=1;
      if(a[x]==1) b[x]=0;
    }
    a[y]++; a[x]--;
  }
  int cnt = 0;
  for(int i = 1; i<=n; i++) if(b[i]) cnt++;
  cout << cnt << endl;
  return 0;
}