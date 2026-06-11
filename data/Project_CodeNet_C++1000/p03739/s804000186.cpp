#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  int n; cin >> n;
  int a[n];
  rep(i,n) cin >> a[i];

  // a[0]>0
  ll sump[n], cntp = 0;
  rep(i,n){
    if (i==0){
      sump[i] = max<ll>(a[i], 1);
      cntp += max<ll>(0,1-a[i]);
    }
    else if (i%2==0){
      sump[i] = max<ll>(sump[i-1] + a[i], 1);
      cntp += max<ll>(0,1-a[i]-sump[i-1]);
    }
    else {
      sump[i] = min<ll>(sump[i-1] + a[i], -1);
      cntp += -min<ll>(0,-1-a[i]-sump[i-1]);
    }
  }

  // a[0]<0
  ll summ[n], cntm = 0;
  rep(i,n){
    if (i==0){
      summ[i] = min<ll>(a[i], -1);
      cntm += -min<ll>(0,-1-a[i]);
    }
    else if (i%2==1){
      summ[i] = max<ll>(summ[i-1] + a[i], 1);
      cntm += max<ll>(0,1-a[i]-summ[i-1]);
    }
    else {
      summ[i] = min<ll>(summ[i-1] + a[i], -1);
      cntm += -min<ll>(0,-1-a[i]-summ[i-1]);
    }
  }
  
  cout << min(cntm, cntp) << endl;


  // cout << fixed << setprecision(6);
  return 0;
}
