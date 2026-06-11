#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

typedef long long ll;

int main() {
  int N,x; cin >>N >>x;
  vector<int> a(N);
  vector<int> b(N);
  rep(i,0,N) {
    cin >>a[i]; b[i]=a[i];
  }
  rep(i,0,N) {
    if (x<b[i]) b[i]=x;
  }
  int i=0;
  while (i<N-1) {
    if (x<b[i]+b[i+1]) b[i+1]=x-b[i];
    i++;
  }
  ll Ans=0;
  rep(i,0,N) Ans+=a[i]-b[i];
  cout <<Ans <<endl;
  return 0;
}
