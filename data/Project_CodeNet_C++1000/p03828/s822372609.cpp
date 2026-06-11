#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <string>
using namespace std;
int main(void){
  int n;
  cin>>n;
  long long int ans=1;
  vector<long long int> sum(1001,1);
  for(int i=1; i<=n; i++){
    long long int count=0;
    int pre=i;
    for(int j=2; j<=n; j++){
      if(pre%j==0){
        count++;
        pre/=j;
        j--;
      }else{
        sum.at(j)+=count;
        count=0;
      }
    }
  }
  for(int i=0; i<=n; i++){
    ans*=sum.at(i);
    ans%=1000000007;
  }
  cout<<ans<<endl;
}