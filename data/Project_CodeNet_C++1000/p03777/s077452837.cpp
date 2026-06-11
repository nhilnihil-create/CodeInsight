#include <bits/stdc++.h>
using namespace std;
 



int main() {
 

  char a,b;
  cin>>a>>b;


  bool flg;
  if(a=='H'){
    if(b=='H')
      flg=true;
    else if(b=='D')
      flg=false;
  }else if(a=='D'){
    if(b=='H')
      flg=false;
    else if(b=='D')
      flg=true;
  }

  if(flg)
    cout<<'H'<<endl;
  else
    cout<<'D'<<endl;

	return 0;
}