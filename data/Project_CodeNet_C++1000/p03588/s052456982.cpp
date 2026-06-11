#include <bits/stdc++.h>
#define r(x,i,n) for(int i = x; i<n; i++)
typedef long long ll;
using namespace std;

int main(){
  int a=0,b=0,n,m,k;
  cin >> k;
  while(k--){
    cin >> n >> m;
    if(n>a){
      a=n;b=m;
    }
  }
  cout << a+b<<endl;
}