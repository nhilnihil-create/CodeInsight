#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX;
#define INFL LLONG_MAX;
typedef long long ll;
using namespace std;

/*ll factorial(int r){
  if(r==0) return 1;
  return factorial(r-1)*r;
}

ll nPr(int n,int r){
  if(r==0) return 1;
  return nPr(n-1,r-1)*n;
}

ll nCr(int n,int r){
  return nPr(n,r)/factorial(r);
}

int main(){
  int n,p; cin >> n >> p;
  int even = 0,odd = 0;



  rep(i,n){
    int a; cin >> a;
    if(a%2) odd++;
    else even++;
  }

  ll ans1 = pow(2,even);

  ll ans2 = 0;

  for(int i=p;i<=odd;i+=2){
    ans2 += nCr(odd,i);
  }

  cout << ans1 * ans2 << endl;


}*/
int main(){
  int n,p; cin >> n >> p;
  int m=0;
  rep(i,n){
    int a; cin >> a;
    if(a%2==1) ++m;
  }

  if(m==0) cout << (p==0 ? (1LL<<n):0) << endl;
  else cout << (1LL<<(n-1)) << endl;
}
