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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar_unlocked(c[i]);
  }
}
int N;
int X;
int res[200000];
int main(){
  int i;
  int k = 2;
  rd(N);
  rd(X);
  if(X==1 || X==2*N-1){
    wt_L("No");
    wt_L('\n');
    return 0;
  }
  wt_L("Yes");
  wt_L('\n');
  for(i=(0);i<(2*N-1);i++){
    if(i == N-1){
      res[i] = X;
      continue;
    }
    if(i == N-2){
      res[i] = 1;
      continue;
    }
    if(i == N  ){
      res[i] = 2*N-1;
      continue;
    }
    if(k==X){
      k++;
    }
    res[i] = k++;
  }
  {
    int Q5VJL1cS;
    for(Q5VJL1cS=(0);Q5VJL1cS<(2*N-1);Q5VJL1cS++){
      wt_L(res[Q5VJL1cS]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20191125-1

// --- original code ---
// int N, X;
// int res[2d5];
// {
//   int k = 2;
//   rd(N,X);
//   if(X==1 || X==2N-1) wt("No"), return 0;
//   wt("Yes");
//   rep(i,2N-1){
//     if(i == N-1) res[i] = X, continue;
//     if(i == N-2) res[i] = 1, continue;
//     if(i == N  ) res[i] = 2N-1, continue;
//     if(k==X) k++;
//     res[i] = k++;
//   }
//   wtLn(res(2N-1));
// }
