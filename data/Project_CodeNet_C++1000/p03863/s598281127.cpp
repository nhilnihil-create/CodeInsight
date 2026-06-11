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
  int i, sz=0;
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar_unlocked(c[i]);
  }
}
int N;
char S[100002];
int main(){
  N = rd(S);
  if(S[0]==S[N-1]){
    N++;
  }
  if(N%2==0){
    wt_L("Second");
    wt_L('\n');
  }
  else{
    wt_L("First");
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190902-1

// --- original code ---
// int N;
// char S[100002];
// {
//   rd(S@N);
//   if(S[0]==S[N-1]) N++;
//   wt( if[N%2==0, "Second", "First"] );
// }
