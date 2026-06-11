#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  int N; cin >>N;
  vector<int> a(N);
  rep(i,0,N) cin >>a[i];
  int Ans=INT_MAX;
  sort(a.begin(),a.end());
  rep_eq(i,a.front(),a.back()) {
    int temp=0;
    rep(j,0,N) temp+=pow((a[j]-i),2);
    Ans=min(Ans,temp);
  }
  cout <<Ans <<endl;
}
