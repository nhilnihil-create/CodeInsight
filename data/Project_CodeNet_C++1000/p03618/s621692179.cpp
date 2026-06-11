#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline void rd(char &c){
  int i;
  for(;;){
    i = getchar_unlocked();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = getchar_unlocked();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = getchar_unlocked();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
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
int N;
char S[200002];
int cnt[26];
int main(){
  int i;
  long long res;
  N = rd(S);
  res = (long long) N * (N+1) / 2 + 1;
  for(i=(0);i<(N);i++){
    cnt[S[i]-'a']++;
  }
  for(i=(0);i<(26);i++){
    res -= (long long) cnt[i] * (cnt[i]+1) / 2;
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20191125-1

// --- original code ---
// int N;
// char S[200002];
// int cnt[26];
// {
//   ll res;
//   rd(S@N);
//   res = (ll) N * (N+1) / 2 + 1;
//   rep(i,N) cnt[S[i]-'a']++;
//   rep(i,26) res -= (ll) cnt[i] * (cnt[i]+1) / 2;
//   wt(res);
// }
