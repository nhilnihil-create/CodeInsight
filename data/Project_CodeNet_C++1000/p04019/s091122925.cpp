#include<bits/stdc++.h>
using namespace std;

int main(){
  string t;
  cin >> t;
  int w=0,s=0,e=0,n=0;
  for(int i=0;i<t.size();i++){
    if(t.at(i)=='W')
      w=1;
    else if(t.at(i)=='N')
      n=1;
    else if(t.at(i)=='E')
      e=1;
    else if(t.at(i)=='S')
      s=1;
  }
  if((n+s==2&&e+w==0)||(n+s==0&&e+w==2)||(n+s+e+w==4))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}