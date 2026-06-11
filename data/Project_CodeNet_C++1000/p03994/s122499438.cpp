#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  long k;
  cin >> k;
  int i = 0;
  int n = s.length();
  while(k>0 && i<n){
    int tmp = (26-(int)(s[i]-'a'))%26;
    if(tmp<=k){
      k-=tmp;
      s[i] = 'a';
    }
    i++;
  }
  if(k>0)s[n-1]=(char)((int)(s[n-1])+k%26);
  cout << s << endl;
}
