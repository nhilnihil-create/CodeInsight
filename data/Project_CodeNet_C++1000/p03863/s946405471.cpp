#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  string s;
  cin >> s;
  int n=s.size();
  if((n%2==0&&s[0]!=s[n-1])||(n%2==1&&s[0]==s[n-1]))cout << "Second" << endl;
  else cout << "First" << endl;
 
}
