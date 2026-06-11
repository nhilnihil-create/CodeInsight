#include <bits/stdc++.h>

using namespace std;

#define rep(i,m,n) for(int i=m;i<n;i++)

typedef long l;

l gcd(l a, l b){
 while(a%b){
  l r=a%b;
   a=b;
   b=r;
 }
return b;
}


int main(){
  l n,x;
  cin >> n >> x;
  
  cout << 3*(n-gcd(n,x)) << endl;
}