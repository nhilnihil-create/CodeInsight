#include <iostream>
using namespace std;
typedef long long ll;


#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep_s(i, start, n) for(int i = start; i < (int)(n); i++)

ll minimi(ll a, ll b){
  if (a>b){
    return b;
  } else{
    return a;
  }
}
int main(void){
  ll N, M, A, B, C, D, E, F, K,L, W, H, P, Q, R, X, Y;
  //ll a[N+1];	
  cin >>A >> B;
  if ((A+B)%3 == 0 || A%3 == 0 || B%3 == 0) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  
}

