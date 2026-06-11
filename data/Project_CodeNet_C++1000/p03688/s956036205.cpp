#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar_unlocked(c[i]);
  }
}
template<class T> int arrCountVal(int N, T A[], T val){
  int i;
  int res = 0;
  for(i=(0);i<(N);i++){
    if(A[i]==val){
      res++;
    }
  }
  return res;
}
int N;
int A[100000];
int main(){
  int mi;
  int mx;
  int x;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  {
    int e98WHCEY;
    int cTE1_r3A;
    if(N==0){
      cTE1_r3A = 0;
    }
    else{
      cTE1_r3A = A[0];
      for(e98WHCEY=(1);e98WHCEY<(N);e98WHCEY++){
        cTE1_r3A = min_L(cTE1_r3A, A[e98WHCEY]);
      }
    }
    mi =cTE1_r3A;
  }
  {
    int xr20shxY;
    int WYIGIcGE;
    if(N==0){
      WYIGIcGE = 0;
    }
    else{
      WYIGIcGE = A[0];
      for(xr20shxY=(1);xr20shxY<(N);xr20shxY++){
        WYIGIcGE = max_L(WYIGIcGE, A[xr20shxY]);
      }
    }
    mx =WYIGIcGE;
  }
  if(mx - mi >= 2){
    wt_L("No");
    wt_L('\n');
    return 0;
  }
  if(mi == mx && mi == N-1){
    wt_L("Yes");
    wt_L('\n');
    return 0;
  }
  x = N - arrCountVal(N,A,mx);
  if((N-x)/2 >= mx-x  &&  mx-x > 0){
    wt_L("Yes");
    wt_L('\n');
  }
  else{
    wt_L("No");
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191125-1

// --- original code ---
// int N, A[1d5];
// {
//   int mi, mx, x;
//   rd(N,A(N));
//   mi = min(A(N));
//   mx = max(A(N));
//   if(mx - mi >= 2) wt("No"), return 0;
//   if(mi == mx && mi == N-1) wt("Yes"), return 0;
//   x = N - arrCountVal(N,A,mx);
//   wt( if[(N-x)/2 >= mx-x > 0, "Yes", "No"] );
// }
