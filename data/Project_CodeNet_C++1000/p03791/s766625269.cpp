#include<iostream>
using namespace std;
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long int li;
int main(){
  int n,k=0;li s=1; cin >>n;
  rep(i,n){
    int a; cin >>a;
    if(2*k==a){
      (s*=k+1)%=MOD;
      k--;
    }
    k++;
  }
  while(k>0){
    (s*=k--)%=MOD;
  }
  printf("%ld",s);
}