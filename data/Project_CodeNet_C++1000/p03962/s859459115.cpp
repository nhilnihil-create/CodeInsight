#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a[3],ans=0,b=0;
  for(int i=0;i<3;i++){
    cin>>a[i];
    for(int j=0;j<i;j++){
      if(a[i]==a[j]){
	b++;
      }
    }
    if(b==0){
      ans++;
    }
    b=0;
  }
  cout<<ans<<"\n";
  return 0;
}