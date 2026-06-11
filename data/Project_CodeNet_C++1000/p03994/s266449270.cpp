#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  string s;
  cin >> s;
  ll k;
  cin >> k;
  int n=s.size();
  for(int i=0;i<n-1;++i){
    if(s[i]=='a')continue;
    int number=s[i]-'a';
    //cout << number << endl;
    int t=26-number;
    //cout << t << endl;
    if(t<=k){
      s[i]='a';
      k=k-t;
    }
  }
  //cout << k << endl;
  if(k>0){
    k=k%26;
    int number=s[n-1]-'a';
    int t=26-number;
    if(t>k){
      //cout << k << endl;
      s[n-1]=char(s[n-1]+k);
    }else{
      k=k-t;
      s[n-1]=char('a'+k);
    }
    //s[n-1]=char(s[n-1]+k);
  }
  cout << s << endl;
  return 0;
}
