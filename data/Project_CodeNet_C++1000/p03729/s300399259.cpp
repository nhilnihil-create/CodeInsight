#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  string a,b,c;
  cin>>a>>b>>c;
  if(a[(a.size())-1]==b[0] && b[(b.size())-1]==c[0]){
    cout<<"YES"<<"\n";
  }
  else{
    cout<<"NO"<<"\n";
  }
  
    return 0;
}