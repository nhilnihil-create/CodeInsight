#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int M;
int A[300][300];
int ok[300];
int cnt[300];
int p[300];
int main(){
  int i, t_ynMSdg;
  int res;
  rd(N);
  rd(M);
  for(i=(0);i<(N);i++){
    {
      int Q5VJL1cS;
      for(Q5VJL1cS=(0);Q5VJL1cS<(M);Q5VJL1cS++){
        rd(A[i][Q5VJL1cS]);A[i][Q5VJL1cS] += (-1);
      }
    }
  }
  for(i=(0);i<(M);i++){
    ok[i] = 1;
  }
  for(i=(0);i<(N);i++){
    cnt[A[i][0]]++;
  }
  res = N;
  for(t_ynMSdg=(0);t_ynMSdg<(M-1);t_ynMSdg++){
    {
      int tU__gIr_;
      int a2conNHc;
      if(M==0){
        a2conNHc = 0;
      }
      else{
        a2conNHc = cnt[0];
        for(tU__gIr_=(1);tU__gIr_<(M);tU__gIr_++){
          a2conNHc = max_L(a2conNHc, cnt[tU__gIr_]);
        }
      }
      chmin(res, a2conNHc);
    }
    {
      int YREPHmFM;
      int jZyWAPpY = 0;
      int jbtyPBGc;
      int ZIeRIny5;
      int iMWUTgY_;
      for(YREPHmFM=(0);YREPHmFM<(((M)-1)+1);YREPHmFM++){
        ZIeRIny5 = cnt[YREPHmFM];
        if(jZyWAPpY==0 || jbtyPBGc<ZIeRIny5){
          jbtyPBGc = ZIeRIny5;
          jZyWAPpY = 1;
          iMWUTgY_ = YREPHmFM;
        }
      }
      ok[iMWUTgY_] = 0;
    }
    for(i=(0);i<(N);i++){
      cnt[A[i][p[i]]]--;
      while(ok[A[i][p[i]]]==0){
        p[i]++;
      }
      cnt[A[i][p[i]]]++;
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20191125-1

// --- original code ---
// int N, M, A[300][300];
// int ok[300], cnt[300], p[300];
// {
//   int res;
//   rd(N,M);
//   rep(i,N) rd((A[i]--)(M));
//   rep(i,M) ok[i] = 1;
//   rep(i,N) cnt[A[i][0]]++;
//   res = N;
//   rep(M-1){
//     res <?= max(cnt(M));
//     ok[argmax(cnt(M))] = 0;
//     rep(i,N){
//       cnt[A[i][p[i]]]--;
//       while(ok[A[i][p[i]]]==0) p[i]++;
//       cnt[A[i][p[i]]]++;
//     }
//   }
//   wt(res);
// }
