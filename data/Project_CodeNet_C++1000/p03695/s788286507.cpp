#include <bits/stdc++.h>
#define rep(i,a,n) for(int i =a; i<n; i++) 
#define ll long long
using namespace std;

int main() {
  int N; cin >> N;
  int a[N]; rep(i,0,N) cin >> a[i];
  
  bool c[8]; rep(i,0,8) c[i] =false;
  int ans =0, legend =0;
  rep(i,0,N) {
    rep(j,1,9) {
      if (a[i] >= 3200) {
        legend++; break;
      }
      if (a[i] >= (j-1)*400 && a[i] < j*400) c[j-1] = true; 
    }
  }
  rep(i,0,8) if(c[i]) ans++;
  
  int minC = ans;
  if (ans==0) minC =1;
  int maxC = ans + legend;

  cout << minC << " " << maxC << endl;
}