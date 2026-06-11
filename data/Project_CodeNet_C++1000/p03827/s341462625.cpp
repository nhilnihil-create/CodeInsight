
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

typedef long long ll;



 int main(){

   int  a=0,maxi=0,n;
  cin>>n;
  string s;

  cin>>s;

  for(int i=0;i<s.length();i++){
    if(s[i] == 'I')
        a ++;
    else if(s[i] == 'D')
        a--;

    maxi = max(maxi,a);
  }

    cout<<maxi<<endl;

 return 0;
 }
