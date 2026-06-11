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
  int K, N; cin >> K >> N;
  int a[N]; rep(i,N) cin >> a[i];
  sort(a,a+N);
  reverse(a,a+N);
  if (a[0]<(K+1)/2) {
    cout << 0 << endl;
  }
  else if (K%2) {
    int k = a[0]-(K+1)/2;
    cout << 2*k << endl;
  }
  else {
    int k = a[0] - K/2;
    cout << 2*k-1 << endl;
  }


  // cout << fixed << setprecision(10);
  
  return 0;
}
