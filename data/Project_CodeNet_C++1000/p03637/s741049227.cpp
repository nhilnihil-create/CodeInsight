#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){

	int n, d0=0, d2=0, d4=0, tmp;
	cin>> n;
  
  	rep(i, n){
      cin>> tmp;
      if(tmp%4==0) d4++;
      else if(tmp%2==0) d2++;
      else d0++;
    }
  
	if(d0<=d4 || (d0==d4+1 && d2==0)) cout<< "Yes" << endl;
	else cout<< "No" << endl;
 
	return 0;
}