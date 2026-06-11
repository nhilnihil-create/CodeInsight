#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
  long long a,b,x;
  cin>>a>>b>>x;
  long long answer=b/x-a/x;
  if(a%x==0) answer+=1;
  cout<<answer<<endl;
  
  return 0;
}