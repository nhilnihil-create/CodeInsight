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
  int A[N]; rep(i,N) cin >> A[i];

  int cnt = 0, s = 0;
  rep(i,N){
    if (i==N-1) cnt++;
    else if (A[i+1]>A[i]){
      if (s==0) s = 1;
      else if (s==1) continue;
      else {
        cnt++;
        s = 0;
      }
    }
    else if (A[i+1]<A[i]){
      if (s==0) s = -1;
      else if (s==-1) continue;
      else {
        cnt++;
        s = 0;
      }
    }
  }
  cout << cnt << endl;

  // cout << fixed << setprecision(10);
  
  return 0;
}

