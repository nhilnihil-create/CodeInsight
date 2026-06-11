#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
int P[20000];
int A[20000];
int B[20000];
int main(){
  int i;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(P[Lj4PdHRW]);P[Lj4PdHRW] += (-1);
    }
  }
  for(i=(0);i<(N);i++){
    A[i] = i * (N+1) + 1;
  }
  for(i=(0);i<(N);i++){
    B[i] = A[N-1-i];
  }
  for(i=(0);i<(N);i++){
    A[P[i]] += i;
  }
  {
    int t_ynMSdg;
    if(N==0){
      putchar_unlocked('\n');
    }
    else{
      for(t_ynMSdg=(0);t_ynMSdg<(N-1);t_ynMSdg++){
        wt_L(A[t_ynMSdg]);
        wt_L(' ');
      }
      wt_L(A[t_ynMSdg]);
      wt_L('\n');
    }
  }
  {
    int tU__gIr_;
    if(N==0){
      putchar_unlocked('\n');
    }
    else{
      for(tU__gIr_=(0);tU__gIr_<(N-1);tU__gIr_++){
        wt_L(B[tU__gIr_]);
        wt_L(' ');
      }
      wt_L(B[tU__gIr_]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20191125-1

// --- original code ---
// int N, P[2d4];
// int A[2d4], B[2d4];
// {
//   rd(N,(P--)(N));
//   rep(i,N) A[i] = i * (N+1) + 1;
//   rep(i,N) B[i] = A[N-1-i];
//   rep(i,N) A[P[i]] += i;
//   wt(A(N));
//   wt(B(N));
// }
