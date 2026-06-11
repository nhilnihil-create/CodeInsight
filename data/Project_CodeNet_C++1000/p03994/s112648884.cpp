#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
char b(char u,int k){
  k=k%26;
  int m='z'-u;
  if(m>=k)return u+k;
  else return 'a'+(k-m-1);
}
int main(){
  string s;
  cin >> s;
  int n=s.size();
  int k;
  cin >> k;
  rep(i,n-1){
    if(s[i]=='a')continue;
    if('z'-s[i]<k){
      k-=('z'-s[i]+1);
      s[i]='a';
    }
  }
  s[n-1]=b(s[n-1],k);
  cout << s << endl;
}
