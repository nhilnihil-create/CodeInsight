#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pint pair<int,int>

const int MAX_N = 5000; //多めに見積もる
const int INF = (1LL<<60)-1;

int dat[2*MAX_N],n;

void init(int a){
  n = 1LL;
  
  while( n < a ){ n *= 2;} 
  
  for(int i = 0; i < 2*MAX_N; i++){ dat[i] = INF;}
  //INF初期化
}

void update(int k, int a){
  
  k += n-1;
  dat[k] = a;
  
  while( k > 0 ){
    k = (k-1)/2;
    dat[k] = min(dat[2*k+1],dat[2*k+2]);
  }
}

int find(int a,int b, int k, int l, int r){
  if( r <= a || b <= l ){ return INF;}
  if( a <= l && r <= b){ return dat[k];}
  else{
    int v1 = find(a,b,2*k+1,l,(l+r)/2);
    int v2 = find(a,b,2*k+2,(l+r)/2,r);
  
  
  return min(v1,v2);
  
  }
}

int N,x;

signed main(void){ 
  
  cin >> N >> x;
  
  init(N+1);
  
  for(int i = 0; i < N; i++){
    int a; cin >> a;
    update(i,a);
  }
  
  int ans = INF;
  
  for(int k = 0; k < N; k++){  //何回回転するかを決めうち
    
    int res = 0;
    
    for(int i = 0; i < N; i++){ 
    
     if( i-k >= 0 ){
      
       res += find(i-k,i+1,0,0,n);
      
    //min{A[i],A[i-1],,, A[i-k]のうちの最小値をセグでもとめる
       
     }
     else{
       
       int r1 = find(0,i+1,0,0,n);
       // A[0],,,A[i]の最小値と、
       int r2 = find(i-k+N,N,0,0,n);
       // A[i-k+N],,, A[N-1]の最小値を求め
       
       res += min(r1,r2); //より小さい方を取る
     }
    }
    
     ans = min(ans, res+k*x);
    
  }
  
  cout << ans << endl;
  
  return 0;
}
    
