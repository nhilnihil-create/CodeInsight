#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main(){
  int W,a,b; cin >>W >>a >>b;
  int ans=0;
  if (a<b && a+W<b) {
    ans=b-(W+a);
  } else if (a>b && b+W<a) {
    ans=a-(W+b);
  }
  cout <<ans <<endl;
  return 0;
}
