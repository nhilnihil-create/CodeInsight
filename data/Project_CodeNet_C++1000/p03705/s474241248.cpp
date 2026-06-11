#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n,a,b;
  cin >> n >> a >> b;
  if(n==1&&a<b)cout << 0;
  else if(a>b)cout << 0;
  else cout << (a+b*(n-1))+1-(b+a*(n-1));
}
