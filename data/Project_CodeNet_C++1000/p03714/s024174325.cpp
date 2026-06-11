#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16]={0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
inline void rd(int &x){
  int k, m=0;
  x=0;
  for(;;){
    k = getchar_unlocked();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = getchar_unlocked();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void wt_L(char a){
  putchar_unlocked(a);
}
inline void wt_L(long long x){
  char f[20];
  int m=0, s=0;
  if(x<0){
    m=1;
    x=-x;
  }
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  if(m){
    putchar_unlocked('-');
  }
  while(s--){
    putchar_unlocked(f[s]+'0');
  }
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
template<class T> struct Heap{
  T *val;
  int size;
  void malloc(const int N){
    val = (T*) std::malloc(N*sizeof(T));
    size = 0;
  }
  void walloc(const int N, void **mem = &wmem){
    walloc1d(&val, N, mem);
    size = 0;
  }
  void free(){
    std::free(val);
  }
  void init(){
    size = 0;
  }
  void up(){
    int m, n=size - 1;
    while(n){
      m = (n-1) / 2;
      if(val[m] <= val[n]){
        break;
      }
      swap(val[m], val[n]);
      n = m;
    }
  }
  void down(){
    int m, n=0;
    for(;;){
      m=2*n+1;
      if(m>=size){
        break;
      }
      if(m+1<size && val[m] > val[m+1]){
        m++;
      }
      if(val[m] >= val[n]){
        break;
      }
      swap(val[m], val[n]);
      n = m;
    }
  }
  T top(){
    return val[0];
  }
  T pop(){
    T res=val[0];
    size--;
    if(size > 0){
      val[0] = val[size];
      down();
    }
    return res;
  }
  void push(const T x){
    val[size++] = x;
    up();
  }
}
;
char memarr[96000000];
int N;
int A[300000];
long long x[2][100001];
int main(){
  Heap<int> h;
  int i, loop;
  long long s;
  wmem = memarr;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(3*N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  h.walloc(N+1);
  for(loop=0;loop<(2);loop++){
    h.init();
    s = 0;
    for(i=0;i<(N);i++){
      s += A[i];
      h.push(A[i]);
    }
    x[loop][0] = s;
    for(i=0;i<(N);i++){
      s += A[N+i];
      h.push(A[N+i]);
      s -= h.pop();
      x[loop][i+1] = s;
    }
    for(i=0;i<(3*N);i++){
      A[i] = -A[i];
    }
    reverse(A, A+3*N);
  }
  s = -4611686016279904256LL;
  for(i=0;i<(N+1);i++){
    chmax(s, x[0][i] + x[1][N-i]);
  }
  wt_L(s);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190827-1

// --- original code ---
// int N, A[3d5];
// ll x[2][100001];
// {
//   int i;
//   ll s;
//   Heap<int> h;
//   rd(N,A(3N));
// 
//   h.walloc(N+1);
// 
//   rep(loop,2){
//     h.init();
//     s = 0;
//     rep(i,N){
//       s += A[i];
//       h.push(A[i]);
//     }
//     
//     x[loop][0] = s;
//     rep(i,N){
//       s += A[N+i];
//       h.push(A[N+i]);
//       s -= h.pop();
//       x[loop][i+1] = s;
//     }
//     rep(i,3N) A[i] = -A[i];
//     reverse(A, A+3N);
//   }
// 
//   s = -ll_inf;
//   rep(i,N+1) s >?= x[0][i] + x[1][N-i];
//   wt(s);
// }
