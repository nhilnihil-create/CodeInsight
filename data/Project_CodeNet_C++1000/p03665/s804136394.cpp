#include <bits/stdc++.h>
using namespace std;
// n > 0 のとき
// sum_{r in [0,n]} binom(n,r)= (1+1)^n= 2^n
// sum_{r in [0,n]} (-1)^r binom(n,r)= (1-1)^n= 0 より、
// sum_{r:odd  in [0,n]} binom(n,r)= 2^{n-1}
// sum_{r:even in [0,n]} binom(n,r)= 2^{n-1}
int main(){
  int N,mod2;
  cin >> N >> mod2;
  
  int Nodd = 0;
  int Neven= 0;
  int buf;
  for(int i=0; i<N; i++){
    cin >> buf;
    if(buf%2==1){ Nodd++;  }
    else        { Neven++; }
  }

  int64_t ans= (Nodd==0) ? ((mod2==0) ? (1LL<<Neven)
                                      : 0)
                         : (1LL<<(Nodd-1))* (1LL<<Neven);

  cout << ans << endl;
}