#include<bits/stdc++.h>
using namespace std;
#define int long long 

// BIT木を実装する

const int MAX_N = 3e7;

int bit[MAX_N]; int n;

void init(const int &N){ 
  
  n = 1LL;
  while( n < N){ n *= 2;} //bitは最初から0だから更新する必要なし
}

void add(int i, const int &x){
  while( i <= n ){ bit[i] += x; i += i& (-i);}
}

int sum(int i){ //a1+...+asまでの和
  int s = 0;
  while( i > 0 ){ s += bit[i]; i -= i&(-i);}
  return s;
}

signed main(void){
  
  int N,K; cin >> N >> K;
 
  
  init(10*N);
    
  
  int ans = 0;
  vector<int> a(N+1,0);
  
  for(int i = 1; i <= N; i++){ //bitは1-indexedで扱うことに注意
    cin >> a[i]; a[i] -= K; 
  }
  
  vector<int> b(N+1,0); b[1] = a[1];
  
  //aとbは0-で、cとBITは1-で扱う
  for(int i = 2; i <= N; i++){ 
    b[i] = b[i-1]+a[i];
  }
 //次にbを座標圧縮する

  vector<int> c(N+1); vector<int> copy(N+1);
  
  for(int i = 0; i <= N; i++){ copy[i] = b[i];} 
  
  sort(copy.begin(),copy.end());
  
  for(int i = 0; i <= N; i++){
    //b[i]が実は何番めかを調べて行く
    
    int test = b[i];
    
    int order = lower_bound(copy.begin(),copy.end(),test)-copy.begin();
    
    c[i] = order+1;
    
  }
  for(int i = 0; i <= N; i++){ 
    
   
    ans += sum(c[i]);
    
    add(c[i],1);
    
  }
  
  cout << ans << endl;
  
  return 0;
}