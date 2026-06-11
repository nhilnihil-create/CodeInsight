#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string a,b,c;
  cin >> a>>b>>c;
  char A=a.at(0)-'a'+'A';
  char B=b.at(0)-'a'+'A';
  char C=c.at(0)-'a'+'A';
  cout<<A<<B<<C<<endl;
}