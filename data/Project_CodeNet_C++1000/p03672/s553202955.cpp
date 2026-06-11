#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  string s;
  cin>>s;
  ll len=s.length();
  s.erase(len-1);
  len--;

  while(len>1){
    if(s.substr(0,len/2)==s.substr(len/2)){
      cout<<len<<endl;
      return 0;
    }
    s.erase(len-1);
    len--;
  }
  return 0;
}
