#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  string s;
  int al[27]={};
  int c=0;
  cin>>s;
  for(int i=0;i<s.size();i++){
    al[s[i]-96]++;
  }
  for(int i=1;i<=26;i++){
    if(al[i]%2!=0){
      c++;
      break;
    }
  }
  if(c==0){
    cout<<"Yes"<<"\n";
  }
  else{
    cout<<"No"<<"\n";
  }
  return 0;
}