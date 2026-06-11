#include<iostream>
#include<string>
using namespace std;
int main()
{
  int n,k,t,i,res;
  string s;
  cin >> s >> k;
  n=s.size();
  for(i=0;i<n;i++){
    t=(int)('z'-s[i]);
    if(k>t&&t<25){
      s[i]='a';
      k-=t+1;
    }
    if(k==0) break;
  }
  if(k>0){
    t=(int)(s[n-1]-'a')+k;
    t%=26;
    s[n-1]='a'+(char)t;
  }
  cout << s << endl;
  return 0;
}