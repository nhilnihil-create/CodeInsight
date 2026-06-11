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
  int N; cin >> N;
  int a[N]; rep(i,N) cin >> a[i];
  sort(a,a+N);
  ll b[N];
  bool c[N];
  rep(i,N){
    if (i==0) b[i] = a[i];
    else b[i] = b[i-1] + a[i];
    if (i<N-1 && 2*b[i]<a[i+1]) c[i] = false;
    else c[i] = true;
  }
  int cnt = 0;
  rep(i,N){
    cnt++;
    if (c[i]==false) cnt = 0;
  }
  cout << cnt << endl;




  // cout << fixed << setprecision(10);
  
  return 0;
}
