#include <iostream>
#include <algorithm>
#include <queue>
#include <cassert>
using namespace std; typedef long long ll; const int MINF=-1e9; typedef pair<int,int> P;

int main() {
  int n; cin>>n;
  int x[n]; for(int i=0;i<n;i++) cin>>x[i];
  int a[n*n]; fill(a,a+n*n,0);
  for(int i=0;i<n;i++) {
    --x[i];
    if (a[x[i]] != 0) return puts("No")*0;
    a[x[i]]=i+1;
  }

  P p[n];
  for(int i=0;i<n;i++) {
    p[i]={x[i],i}; // i-1個i+1が必要
  }
  sort(p,p+n);
  int j=0;
  for(P y:p) {
    for(int i=0;i<y.second;i++) {
      while(a[j]!=0) {
        j++; if (j>=y.first) return puts("No")*0; // j<n*nも伴う
      }
      a[j]=y.second+1;
    }
  }
  // この時点で、o[i]=i+1（残りn-1-i）
  j=0;
  for(P y:p) {
    for(int i=0;i<n-1-y.second;i++) {
      while(a[j]!=0 || j<y.first) {
        j++; if (j>=n*n) return puts("No")*0; // j<n*nも伴う
      }
      a[j]=y.second+1;
    }
  }

  cout<<"Yes"<<endl;
  for(int i=0;i<n*n;i++) cout<<a[i]<<" ";
  cout<<endl;
}