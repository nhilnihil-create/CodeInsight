#include <bits/stdc++.h>
using namespace std;
signed main(){
  char a[100],b='A';
  int c=1,d,e;
  cin>>d>>e;
  for(;;){
    cin>>a;
    if(a[0]=='s' && a[1]=='n' && a[2]=='u' && a[3]=='k' && a[4]=='e'){
      cout<<b<<c<<endl;
      return(0);
    }
    else{
      b++;
      if(b-e=='A'){
	b='A';
	c++;
      }
    }
  }	
  return(0);
}
