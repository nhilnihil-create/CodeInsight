#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;


int main(){
  string s; 
  cin >> s;
  int n=s.size();
  int ag=0,zg=0;
  for(int i=0;i<n;i++){
    if(s[i]=='A'){ag=i;break;}
  }
  rep(i,n){
    if(s[n-i-1]=='Z'){zg=n-i-1;break;}
  }
  cout << zg-ag+1 << endl;
}