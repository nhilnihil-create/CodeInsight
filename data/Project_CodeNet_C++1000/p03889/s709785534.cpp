#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
 
 
int main()
{
  string S;
  cin>>S;
  bool flag=true;
 
  for(int i=0;i<S.size();i++){
    if(abs(S[i]-S[S.size()-1-i])!=1&&abs(S[i]-S[S.size()-1-i])!=2)
      flag=false;
  }
 
  if(flag)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;  
 
  return 0;
}