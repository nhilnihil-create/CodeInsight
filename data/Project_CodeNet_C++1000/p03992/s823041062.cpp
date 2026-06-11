#include<iostream>
#include<map>
using namespace std;
#define repa(i,a,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
typedef long int li;

int main(){

  string s; cin >> s;
  rep(i,4) cout << s[i];
  cout << " ";
  repa(i,4,s.size()) cout << s[i];
  cout << "\n";
}

  




