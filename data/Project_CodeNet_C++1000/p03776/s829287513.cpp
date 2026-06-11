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
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
}
template<class T1> void rsortA_L(int N, T1 a[], void *mem = wmem){
  sortA_L(N, a, mem);
  reverse(a, a+N);
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
inline void rd(long long &x){
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
inline void wt_L(double x){
  printf("%.15f",x);
}
char memarr[96000000];
int N;
int A;
int B;
long long V[50];
long long c[51][51];
int main(){
  double r1;
  int i, m, u;
  long long r2=0;
  wmem = memarr;
  rd(N);
  rd(A);
  rd(B);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
      rd(V[Lj4PdHRW]);
    }
  }
  rsortA_L(N,V);
  for(i=0;i<(51);i++){
    c[i][0] = 1;
  }
  for(i=(1);i<(51);i++){
    int j;
    for(j=(1);j<(51);j++){
      c[i][j] = c[i-1][j-1] + c[i-1][j];
    }
  }
  u = m = 0;
  for(i=0;i<(N);i++){
    if(V[i] > V[A-1]){
      u++;
    }
    if(V[i]==V[A-1]){
      m++;
    }
  }
  if(u){
    B = A;
  }
  {
    int KL2GvlyY;
    long long Q5VJL1cS;
    if(A==0){
      Q5VJL1cS = 0;
    }
    else{
      Q5VJL1cS = V[0];
      for(KL2GvlyY=(1);KL2GvlyY<(A);KL2GvlyY++){
        Q5VJL1cS += V[KL2GvlyY];
      }
    }
    r1 = (double)Q5VJL1cS/ A;
  }
  for(i=(A);i<(B+1);i++){
    if(i-u >= 0){
      r2 += c[m][i-u];
    }
  }
  wt_L(r1);
  wt_L('\n');
  wt_L(r2);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190902-1

// --- original code ---
// int N, A, B;
// ll V[50];
// 
// ll c[51][51];
// {
//   int i, u, m;
//   double r1;
//   ll r2 = 0;
//   
//   rd(N,A,B,V(N));
//   rsortA(N,V);
// 
//   rep(i,51) c[i][0] = 1;
//   rep(i,1,51) rep(j,1,51) c[i][j] = c[i-1][j-1] + c[i-1][j];
// 
//   u = m = 0;
//   rep(i,N){
//     if(V[i] > V[A-1]) u++;
//     if(V[i]==V[A-1]) m++;
//   }
//   if(u) B = A;
// 
//   r1 = (double)sum(V(A)) / A;
//   rep(i,A,B+1) if(i-u >= 0) r2 += c[m][i-u];
// 
//   wtLn(r1,r2);
// }
