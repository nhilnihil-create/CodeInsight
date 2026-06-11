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
  int T[N], tot = 0; 
  rep(i,N) cin >> T[i], tot+=T[i];
  int M; cin >> M;
  int P[M], X[M]; rep(i,M) cin >> P[i] >> X[i];

  rep(i,M){
    cout << tot-T[P[i]-1]+X[i] << endl;
  }
  

  // cout << fixed << setprecision(6);
  return 0;
}
