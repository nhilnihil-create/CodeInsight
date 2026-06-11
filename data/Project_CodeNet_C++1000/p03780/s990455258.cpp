#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
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
inline void wt_L(int x){
  int s=0;
  int m=0;
  char f[10];
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
int N;
int K;
int A[5000];
int main(){
  wmem = memarr;
  int res;
  bitset<5001> dp;
  rd(N);
  rd(K);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  sortA_L(N,A);
  while(N && A[N-1] >= K){
    N--;
  }
  int KL2GvlyY;
  int Q5VJL1cS;
  int e98WHCEY;
  KL2GvlyY = 0;
  Q5VJL1cS = N;
  while(KL2GvlyY < Q5VJL1cS){
    int i;
    if((KL2GvlyY + Q5VJL1cS)%2==0){
      e98WHCEY = (KL2GvlyY + Q5VJL1cS) / 2;
    }
    else{
      e98WHCEY = (KL2GvlyY + Q5VJL1cS + 1) / 2;
    }
    dp.reset();
    dp[0] = true;
    for(i=(0);i<(N);i++){
      if(i!=e98WHCEY-1){
        dp |= (dp << A[i]);
      }
    }
    for(i=(K-A[e98WHCEY-1]);i<(K);i++){
      if(dp[i]){
        break;
      }
    }
    if(i==K){
      KL2GvlyY = e98WHCEY;
    }
    else{
      Q5VJL1cS = e98WHCEY - 1;
    }
  }
  res =Q5VJL1cS;
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190925-1

// --- original code ---
// int N, K, A[5000];
// {
//   int res;
//   bitset<5001> dp;
//   rd(N,K,A(N));
//   sortA(N,A);
//   while(N && A[N-1] >= K) N--;
//   res = bsearch_max[int,x,0,N][
//     dp.reset();
//     dp[0] = true;
//     rep(i,N) if(i!=x-1) dp |= (dp << A[i]);
//     rep(i,K-A[x-1],K) if(dp[i]) break;
//   ](i==K);
//   wt(res);
// }
