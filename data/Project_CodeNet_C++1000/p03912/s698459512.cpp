#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int kind[100100];

int main(){
  ll N,M; cin >> N >> M;
  
  vector<ll> vec(M,0); // vec[i]はMで割ってi余る要素の個数
  vector<ll> same(M,0); // same[i]はMで割ってi余るグループのうち同一なものの個数
  
  
  for(int i = 0; i < N; i++){
    ll X; cin >> X; kind[X]++;
    vec[X%M]++;
  }
  
  for(ll i = 0; i < 100100; i++){
    same[i%M] += (kind[i]/2)*2;
    }
  
  ll cnt = 0;
  
  // == 0 or == M/2は特別扱い
  cnt += vec[0]/2;
  if( M%2 == 0 ){ cnt += vec[(M/2)]/2;}
  
  for(ll x = 1; x <= (M-1)/2; x++){
    // x と M-xについてみる
    ll r1 = vec[x];
    ll r2 = vec[M-x];
    
    ll res = min(r1,r2); //両方の組みからできるペアの数は以下の通り
    
    cnt += res;
    
    same[x] -= max(0LL,res-(vec[x]-same[x])); //ここがおかしい
    same[M-x] -= max(0LL,res-(vec[M-x]-same[M-x]));
    
  }
  
  
  //残りは同じグループ同士で、同じ数をくっつけあう
  if( M % 2 == 0){ same[M/2] = 0;}
  
  for(int x = 1; x <= M-1; x++){
    
    cnt += max(0LL,same[x])/2;
    
  }
  
  cout << cnt << endl;
  
  
  return 0;
}
   