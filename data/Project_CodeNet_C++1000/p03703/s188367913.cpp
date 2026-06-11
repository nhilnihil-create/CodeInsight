#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
inline void rd(int &x){
  int k;
  int m=0;
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
  int s=0;
  int m=0;
  char f[20];
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
template<class T> long long inversion(int N, T A[], void *mem=wmem){
  int i;
  int j;
  int k;
  int p;
  int n1;
  int n2;
  T *x;
  T *y;
  long long res = 0;
  walloc1d(&x, N, &mem);
  walloc1d(&y, N, &mem);
  for(i=(0);i<(N);i++){
    x[i] = A[i];
  }
  for(k=0;k<N;k+=4){
    n1 =min_L(4, N-k);
    for(j=n1;j;j--){
      int ZIeRIny5 = j;
      for(i=(1);i<(ZIeRIny5);i++){
        if(x[k+i-1] > x[k+i]){
          swap(x[k+i-1], x[k+i]);
          res++;
        }
      }
    }
  }
  p = 4;
  while(p<N){
    for(k=0;k<N;k+=2*p){
      n1 =min_L(p, N-k);
      n2 =min_L(p, N-k-n1);
      i = j = 0;
      while(i<n1 && j<n2){
        if(x[k+i] <= x[k+n1+j]){
          y[k+i+j] = x[k+i];
          i++;
        }
        else{
          y[k+i+j] = x[k+n1+j];
          res += n1-i;
          j++;
        }
      }
      while(i<n1){
        y[k+i+j] = x[k+i];
        i++;
      }
      while(j<n2){
        y[k+i+j] = x[k+n1+j];
        j++;
      }
    }
    swap(x,y);
    p *= 2;
  }
  return res;
}
int N;
int K;
int A[200000];
long long s[200001];
int main(){
  int i;
  wmem = memarr;
  long long res;
  rd(N);
  rd(K);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    s[i+1] = s[i] + A[i] - K;
  }
  res = (long long) N * (N+1) / 2 - inversion(N+1, s);
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20191123-1

// --- original code ---
// int N, K, A[2d5];
// ll s[200001];
// {
//   ll res;
//   rd(N,K,A(N));
//   rep(i,N) s[i+1] = s[i] + A[i] - K;
//   res = (ll) N * (N+1) / 2 - inversion(N+1, s);
//   wt(res);
// }
