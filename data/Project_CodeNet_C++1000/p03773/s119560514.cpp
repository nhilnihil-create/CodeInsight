#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define REP(i,a,n) for(int (i)=(a); (i)<(int)(n); (i)++)
#define rep(i,n) REP(i,0,n)
#define vec vector 


int char_to_int(char c){
  switch(c){
    case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	default: return 0;
  }
}

ll digit(ll N){
  ll res;
  res = floor(log10(N)) + 1;
  return res;
}



int main(){
  int A, B;
  cin >> A >> B;
  
  int res = A + B;
  if(res >= 24) res -= 24;
  
  cout << res;
         
}