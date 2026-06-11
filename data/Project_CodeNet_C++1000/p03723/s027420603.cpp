#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main() {
  int A,B,C;
  cin>>A>>B>>C;
  rep(i,100000000){
      if(A==B&&B==C)
      {
        	if(i==0){
              if(A%2==1||B%2==1||C%2==1){
              cout<<0<<endl;
              break;
              }
            }
          cout<<-1<<endl;
        	break;
      }
    if(i==0){
      	if(A%2==1||B%2==1||C%2==1){
              cout<<0<<endl;
              break;
        }
            }
      int D=A;
      int E=B;
      int F=C;
      A=(E+F)/2;
      B=(D+F)/2;
      C=(D+E)/2;
      if(A%2==1||B%2==1||C%2==1){
          cout<<i+1<<endl;
        break;
      }
  }
}
