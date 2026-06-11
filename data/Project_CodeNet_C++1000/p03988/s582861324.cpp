#include <iostream>
#include <algorithm>
#include <queue>
#include <cassert>
#include <set>
using namespace std; typedef long long ll; const int MINF=-1e9; typedef pair<int,int> P;

int main() {
  int n; cin>>n;
  int b[n], mx=0; fill(b,b+n,0);
  for(int i=0;i<n;i++) {
    int a; cin>>a; b[a]++;
    mx=max(mx,a);
  }
  if (mx==1) {
    if (n==2) return puts("Possible")*0;
    else return puts("Impossible")*0;
  }
  if (mx%2==0) {b[mx/2]--; if (b[mx/2]<0) return puts("Impossible")*0;}
  //cout<<3<<endl;
  for(int i=mx/2+1; i<=mx; i++) {
    b[i]-=2; if (b[i] < 0) return puts("Impossible")*0;
  }
  for(int i=1;i<=mx/2+(mx%2);i++) {
    if (b[i] != 0) return puts("Impossible")*0;
  }
  cout<<"Possible"<<endl;
}