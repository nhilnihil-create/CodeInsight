#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  char a,b;
  cin>>a>>b;
  if(a=='H'){
    if(b=='H'){
      cout<<'H';
    }
    else if(b=='D'){
      cout<<'D';
    }
  }
  else if(a=='D'){
    if(b=='H'){
      cout<<'D';
    }
    else if(b=='D'){
      cout<<'H';
    }
  }
}
