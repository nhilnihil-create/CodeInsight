#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
#define R(i,n) for(int i = 1; i<=n; i++)
typedef long long ll;
using namespace std;

int main(){
  ll n,m=0;
  cin >> n;
  R(i,n){
    m+=i;
    if(m>=n){
      cout << i << endl;
      break;
    }
  }
}