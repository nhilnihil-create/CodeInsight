#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  int A,B;cin>>A>>B;
  if(A==1&&B!=1) cout << "Alice" << endl;
  if(A==1&&B==1) cout << "Draw" << endl;
  if(A!=1&&B==1) cout << "Bob" << endl;
  if(A!=1&&B!=1){
    if(A>B) cout << "Alice" << endl;
    if(A<B) cout << "Bob" << endl;
    if(A==B) cout << "Draw" << endl;
  }
}
