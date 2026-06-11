#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  string s;
  cin >> s;
  int n=s.size();
  int m=n/2;
  int cnt=0;
  rep(i,n)if(s[i]=='p')cnt++;
  cout << m-cnt << endl;
}
