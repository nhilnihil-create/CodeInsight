#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll int64_t
#define all(v) v.begin(), v.end()
#define bitrep(n) for(int bit=0;bit<(1<<n);bit++)

//貪欲法はクソ
int main() {

  int N; cin >> N ;

  vector<int> A(N); rep(i,N) cin >> A[i];

  sort(all(A));

  reverse(all(A));

  ll ans=0;

  int x=0;

  for(int i=0;i<N;){
    int j=0;
    while(A[i+j]==A[i]){
      j++;
      if(i+j>=N) break;
    }

    if(j>=4){
      if(x!=0) ans=(ll)x*A[i];//ここにきづかんかったのは悪かった。ただllはまじで勝手に処理しろ
      else ans=(ll)A[i]*A[i];
      break;
      }

    else if(j==3||j==2){
      if(x!=0){
        ans=(ll)x*A[i]; break;//llぐらい自分で処理して
      }
      else x=A[i];
    }
    i+=j;
    
  }

  cout << ans << endl;
  

  return 0;
}