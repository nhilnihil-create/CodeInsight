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
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2> *arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int A[100000];
int ind[100000];
long long res[100000];
int main(){
  int i;
  wmem = memarr;
  int mi = 1073709056;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    ind[i] = i;
  }
  sortA_L(N, A, ind);
  for(i=(N)-1;i>=(0);i--){
    chmin(mi, ind[i]);
    if(i){
      res[mi] += (long long) (A[i] - A[i-1]) * (N - i);
    }
    else{
      res[mi] += (long long) (A[i]) * (N - i);
    }
  }
  {
    int KL2GvlyY;
    for(KL2GvlyY=(0);KL2GvlyY<(N);KL2GvlyY++){
      wt_L(res[KL2GvlyY]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190925-1

// --- original code ---
// int N, A[1d5];
// int ind[1d5];
// ll res[1d5];
// {
//   int mi = int_inf;
//   rd(N,A(N));
//   rep(i,N) ind[i] = i;
//   sortA(N, A, ind);
//   rrep(i,N){
//     mi <?= ind[i];
//     res[mi] += (ll) (if[i, A[i] - A[i-1], A[i]]) * (N - i);
//   }
//   wtLn(res(N));
// }
