#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  ll T[N],A[N];
  rep(i,N) cin >> T[i];
  rep(i,N) cin >> A[i];
  pair<ll, ll> h[N];//高さ、決定:0 それ以下:1
  h[0] = mp(T[0],0);
  rep1(i,N-1){
    if(T[i] > T[i-1]){
      h[i] = mp(T[i],0);
    }else{
      h[i] = mp(T[i],1);
    }
  }
  if(h[N-1].first < A[0]){
    cout << 0 << endl;
    return 0;
  }
  else if(h[N-1].first > A[0] && h[N-1].second==0){
    cout << 0 << endl;
    return 0;
  }
  h[N-1].first = A[0];
  ll ans=1LL;
  for(int i=N-2; i>=0; i--){
    if(A[i] > A[i+1]){//決定      
      if(h[i].first < A[i]){
	cout << 0 << endl;
	return 0;
      }
      else if(h[i].first > A[i] && h[i].second==0){
	cout << 0 << endl;
	return 0;
      }
      h[i].first = A[0];      
    }
    else{ //未定
      if(h[i].second==0){
	if(A[i] < h[i].first){
	  cout << 0 << endl;
	  return 0;
	}	
      }
      else{
	ans = (ans * min(h[i].first, A[i]))%((ll)1e9+7);
      }
    }

  }
  cout << ans << endl;
  return 0;
    

}
