#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n,m;
  cin >> n >> m;
  if(n*2>m){
    cout << m/2;
  }
  else{
    cout << n+(m-n*2)/4;
  }
}
