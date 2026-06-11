#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main(){
  char a,b; cin >>a >>b;

  if (a=='H') {
    if (b=='H') cout <<'H' <<endl;
    else cout <<'D' <<endl;
  } else if (b=='H') cout <<'D' <<endl;
  else cout <<'H' <<endl;
  return 0;
}
