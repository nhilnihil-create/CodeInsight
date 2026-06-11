#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#define pb push_back
#define mod 1000000007
using namespace std;
typedef long long int ll;
 
int main(void){
  int h,w;
  cin>>h>>w;
  string s;
  for(int i=1;i<=h;i++){
    char c='A';
    for(int j=1;j<=w;j++){
      cin>>s;
      if(s=="snuke"){
        cout<<c<<i<<endl;
      }
      c++;
    }
  }
  return 0;
}